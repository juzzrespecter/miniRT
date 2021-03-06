/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning_loops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:28 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 18:07:11 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	lightning_loops_5(t_ray *ray, t_objs *o_lst, double len)
{
	t_tr	*tr_aux;
	double	t;

	tr_aux = o_lst->tr;
	while (tr_aux)
	{
		t = collision_triangle(tr_aux, ray);
		if (t > ERROR && t < len)
			return (true);
		tr_aux = tr_aux->next;
	}
	return (false);
}

static bool	lightning_loops_4(t_ray *ray, t_objs *o_lst, double len)
{
	t_cy	*cy_aux;
	double	t;

	cy_aux = o_lst->cy;
	while (cy_aux)
	{
		t = collision_cylinder(cy_aux, ray);
		if (t > ERROR && t < len)
			return (true);
		cy_aux = cy_aux->next;
	}
	return (lightning_loops_5(ray, o_lst, len));
}

static bool	lightning_loops_3(t_ray *ray, t_objs *o_lst, double len)
{
	t_sq	*sq_aux;
	double	t;

	sq_aux = o_lst->sq;
	while (sq_aux)
	{
		t = collision_square(sq_aux, ray);
		if (t > ERROR && t < len)
			return (true);
		sq_aux = sq_aux->next;
	}
	return (lightning_loops_4(ray, o_lst, len));
}

static bool	lightning_loops_2(t_ray *ray, t_objs *o_lst, double len)
{
	t_pl	*pl_aux;
	double	t;

	pl_aux = o_lst->pl;
	while (pl_aux)
	{
		t = collision_plane(pl_aux->orientation, pl_aux->coord, ray);
		if (t > ERROR && t < len)
			return (true);
		pl_aux = pl_aux->next;
	}
	return (lightning_loops_3(ray, o_lst, len));
}

bool		lightning_loops(t_ray *ray, t_objs *o_lst, double len)
{
	t_sp	*sp_aux;
	double	t;

	sp_aux = o_lst->sp;
	while (sp_aux)
	{
		t = collision_sphere(sp_aux, ray);
		if (t > ERROR && t < len)
			return (true);
		sp_aux = sp_aux->next;
	}
	return (lightning_loops_2(ray, o_lst, len));
}
