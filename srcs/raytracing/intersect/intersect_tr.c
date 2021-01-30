/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:50:40 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:13 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static double	inter_tr2(t_ray r, t_triangle tr, t_vector *e1, t_vector *e2)
{
	t_vector	h;
	t_vector	s;
	t_vector	q;

	(*e1) = sub_vect(tr.p2, tr.p1);
	(*e2) = sub_vect(tr.p3, tr.p1);
	h = cross(r.d, *e2);
	tr.a = dot_vect(*e1, h);
	if (tr.a > -EPSILON && tr.a < EPSILON)
		return (0);
	tr.f = 1.0 / tr.a;
	s = sub_vect(r.o, tr.p1);
	tr.u = tr.f * dot_vect(s, h);
	if (tr.u < 0.0 || tr.u > 1.0)
		return (0);
	q = cross(s, *e1);
	tr.v = tr.f * dot_vect(r.d, q);
	if (tr.v < 0.0 || tr.u + tr.v > 1.0)
		return (0);
	return (tr.f * dot_vect(*e2, q));
}

int				inter_tr(t_ray ray, t_triangle triangle, t_inter_info *i_i)
{
	t_vector	edge1;
	t_vector	edge2;
	t_vector	normal;
	double		t;

	t = inter_tr2(ray, triangle, &edge1, &edge2);
	if (t > EPSILON)
	{
		i_i->t = t;
		i_i->inter = add_vect(ray.o, mult_vect(ray.d, t));
		normal = normalize_vect(cross(edge1, edge2));
		i_i->normal = process_normal(ray, normal);
		return (1);
	}
	return (0);
}
