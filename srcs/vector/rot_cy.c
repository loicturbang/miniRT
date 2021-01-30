/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:58:50 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:16:25 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static t_vector	calculate_rot(t_vector *c2, t_vector *c3, t_vector rot, \
												t_vector to)
{
	t_vector	c1;
	t_vector	v;
	double		c;
	double		s;
	double		r;

	v = cross(to, rot);
	c = dot_vect(rot, to);
	s = norm2_vect(v);
	r = ((1 - c) / s);
	c1 = vector(-r * (pow(v.y, 2) + pow(v.z, 2)) + 1, r * v.x * \
									v.y - v.z, r * v.x * v.z + v.y);
	(*c2) = vector(r * v.x * v.y + v.z, -r * (pow(v.x, 2) + \
					pow(v.z, 2)) + 1, r * v.y * v.x - v.x);
	(*c3) = vector(r * v.x * v.z - v.y, r * v.y * v.z - v.x, -r * \
					(pow(v.x, 2) + pow(v.y, 2)) + 1);
	return (c1);
}

t_vector		apply_rot(t_vector pos, t_vector dir, t_vector rot)
{
	t_vector c1;
	t_vector c2;
	t_vector c3;
	t_vector prev;

	if (dir.x == 0 && dir.y < 0 && dir.z == 0)
		pos = vector(pos.x, pos.y, -pos.z);
	else if (!(dir.x == 0 && dir.y != 0 && dir.z == 0))
	{
		prev = pos;
		c1 = calculate_rot(&c2, &c3, rot, dir);
		pos = vector(dot_vect(c1, prev), dot_vect(c2, prev), \
										dot_vect(c3, prev));
	}
	return (pos);
}
