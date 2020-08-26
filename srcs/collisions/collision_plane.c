/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:18:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/25 19:38:35 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_3dvec *collision_plane(t_pl *pl, t_3dvec *ray)
{
	float point[3];
	float d;

	d = dot(pl->normal, pl->coord);
	if (!(point_in_plane(pl->normal, ray, d, point)))
		return (NULL);
	point_found(point, pl->normal, pl->color, ray);
	return (ray);
}
