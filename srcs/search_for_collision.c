/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:05:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 19:16:08 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void search_for_collision(t_objlst *obj_lst, t_3dvec *ray)
{
	if (obj_lst->sp)
		sp_loop(obj_lst->sp, ray);
	if (obj_lst->pl)
		pl_loop(obj_lst->pl, ray);
	if (obj_lst->sq)
		sq_loop(obj_lst->sq, ray);
	if (obj_lst->cy)
		cy_loop(obj_lst->cy, ray);
	if (obj_lst->tr)
		tr_loop(obj_lst->tr, ray);
}
