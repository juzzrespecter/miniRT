/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:01:33 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/30 19:26:32 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	fov_check(char *fov)
{
	int	fov_int;
	int	i;

	i = 0;
	if (!ft_isdigit(fov[i]))
		return (false);
	fov_int = ft_atoi(fov);
	if (fov_int < 0 || fov_int > 180)
		return (false);
	while (ft_isdigit(fov[i]))
		i++;
	return (!fov[i] ? true : false);
}

static void	add_cam_to_back(t_rt *index, t_cam *cam)
{
	t_cam	*aux;

	aux = index->cam_lst;
	if (!aux)
		index->cam_lst = cam;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = cam;
	}
}

bool		build_cam(char **scene_line, t_rt *index)
{
	char	*coord;
	char	*vector;
	char	*fov;
	t_cam	*cam;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	vector = scene_line[2];
	fov = scene_line[3];
	if (!(coord_check(coord) && vector_check(vector) && fov_check(fov)))
		return (false);
	if (!(cam = malloc(sizeof(t_cam))))
		return (false);
	ft_bzero(cam, sizeof(t_cam));
	cam->coord = array_to_vector(coord);
	cam->orientation = v_normalize(array_to_vector(vector));
	cam->fov = ft_atoi(fov);
	cam->matrix = matrix_cam2world(cam->orientation);
	add_cam_to_back(index, cam);
	return (true);
}
