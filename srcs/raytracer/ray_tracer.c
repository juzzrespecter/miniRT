/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:21:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/30 18:58:40 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray	build_ray(float x, float y, t_cam *cam)
{
	t_vector	dir_screen;
	t_ray		ray;

	ft_bzero(&ray, sizeof(t_ray));
	dir_screen.x = x;
	dir_screen.y = y;
	dir_screen.z = -1;
	dir_screen = v_normalize(dir_screen);
	ray.dir = v_normalize(vmprod(dir_screen, cam->matrix));
	ray.origin = cam->coord;
	return (ray);
}

static float	x_pixel(t_rtindex *index, int x, t_cam *cam)
{
	float	x_pixel;
	float	ndc_pixel;
	float	ratio;

	ratio = (float)index->res_x / (float)index->res_y;
	ndc_pixel = (x + 0.5) / index->res_x;
	x_pixel = (2 * ndc_pixel - 1)  * ratio * tan((cam->fov / 2)  * M_PI / 180);
	return (x_pixel);
}

static float	y_pixel(t_rtindex *index, int y, t_cam *cam)
{
	float	y_pixel;
	float	ndc_pixel;

	ndc_pixel = (y + 0.5) / index->res_y;
	y_pixel = (1 - 2 * ndc_pixel) * tan((cam->fov / 2) * M_PI / 180);
	return (y_pixel);
}

char			*ray_tracer(t_rtindex *index, t_cam *cam)
{
	t_ray	ray;
	t_point	*point;
	int		x;
	int		y;
	int		i;

	//hay que destruir imagenes en exit_failure
	x = 0;
	y = 0;
	cam->img_ptr = mlx_new_image(index->mlx_ptr, index->res_x, index->res_y);
	cam->img = mlx_get_data_addr(cam->img_ptr, &cam->bpp, &cam->sl, &cam->e);
	if (!cam->img)
		exit_failure(index, "Error: mlx couldn't create img.");
	while (index->res_y > y)
	{
		while (index->res_x > x)
		{
			i = (x * (cam->bpp / 8) + (y * cam->sl));
			ray = build_ray(x_pixel(index, x, cam), y_pixel(index, y, cam), cam);
			if(!(point = collision_loops(index->o_lst, &ray)))
				exit_failure(index, "Error: malloc failed to assign dynamic memory.");
			*(unsigned int *)(cam->img + i) = pixel_color(index->o_lst, point);
			x++;
		}
		x = 0;
		y++;
	}
	return (cam->img);
}