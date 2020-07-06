/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_error_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:48:54 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 16:27:42 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool a_error_check(char **scene_line)
{
	char *light;
	char *color;

	if (!check_scene_array(scene_line, 3))
		return (false);
	light = scene_line[1];
	color = scene_line[2];
	return (light_check(light) && color_check(color) ? true : false);
}
