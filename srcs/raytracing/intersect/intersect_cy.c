/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:17:46 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:10 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static double	dist(t_vector a, t_vector b)
{
	double dist;

	dist = sqrt(norm2_vect(sub_vect(a, b)));
	return (dist);
}

static double	intersect_caps(t_ray ray, t_cylinder cy, t_vector pos)
{
	t_vector	tmp;
	double		a;
	double		b;
	double		t0;

	t0 = 0;
	tmp = sub_vect(ray.o, pos);
	a = dot_vect(tmp, cy.dir);
	b = dot_vect(ray.d, cy.dir);
	if (!(b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0)))
		t0 = -a / b;
	return (t0);
}

static double	calc_c(t_ray ray, t_cylinder cy, t_vector g_b, t_vector g_t)
{
	return (dot_vect(cross(sub_vect(ray.o, g_b), sub_vect(g_t, g_b)), \
		cross(sub_vect(ray.o, g_b), sub_vect(g_t, g_b))) - \
		((cy.ray / 2) * (cy.ray / 2) * dot_vect(sub_vect(g_t, g_b), \
		sub_vect(g_t, g_b))));
}

static void		infinity_cy(t_ray ray, t_cylinder cy, \
							t_vector *g_normal, double *g_t_min)
{
	t_vector	p;
	double		t0;

	cy.a = dot_vect(cross(ray.d, sub_vect(cy.g_t, cy.g_b)), cross(ray.d, \
													sub_vect(cy.g_t, cy.g_b)));
	cy.b = 2 * dot_vect(cross(ray.d, sub_vect(cy.g_t, cy.g_b)), \
					cross(sub_vect(ray.o, cy.g_b), sub_vect(cy.g_t, cy.g_b)));
	cy.c = calc_c(ray, cy, cy.g_b, cy.g_t);
	if (pow(cy.b, 2) - 4 * cy.a * cy.c > 0)
	{
		t0 = (-cy.b - sqrt(pow(cy.b, 2) - 4 * cy.a * cy.c)) / (2 * cy.a);
		if (t0 < 0)
			t0 = (-cy.b + sqrt(pow(cy.b, 2) - 4 * cy.a * cy.c)) / (2 * cy.a);
		p = add_vect(ray.o, mult_vect(ray.d, t0));
		p = apply_rot(p, cy.dir, vector(0, 1, 0));
		cy.g_b = apply_rot(cy.g_b, cy.dir, vector(0, 1, 0));
		cy.g_t = apply_rot(cy.g_t, cy.dir, vector(0, 1, 0));
		if (t0 < *g_t_min && p.y >= cy.g_b.y && p.y <= cy.g_t.y \
												&& (*g_t_min = t0))
		{
			p = apply_rot(p, vector(0, 1, 0), cy.dir);
			*g_normal = normalize_vect(sub_vect(p, cy.o));
		}
	}
}

int				inter_cy(t_ray ray, t_cylinder cy, t_inter_info *i_i)
{
	double		t0;
	double		g_t_min;
	t_vector	g_normal;

	t0 = 0;
	g_t_min = 10E37;
	cy.ray = cy.ray * 2;
	cy.g_b = sub_vect(cy.o, mult_vect(normalize_vect(cy.dir), cy.height / 2));
	cy.g_t = add_vect(cy.o, mult_vect(normalize_vect(cy.dir), cy.height / 2));
	t0 = intersect_caps(ray, cy, cy.g_t);
	i_i->inter = add_vect(ray.o, mult_vect(ray.d, t0));
	if (t0 > 0 && dist(i_i->inter, cy.g_t) <= cy.ray / 2 && (g_t_min = t0))
		g_normal = process_normal(ray, cy.dir);
	t0 = intersect_caps(ray, cy, cy.g_b);
	i_i->inter = add_vect(ray.o, mult_vect(ray.d, t0));
	if (t0 > 0 && dist(i_i->inter, cy.g_b) <= cy.ray / 2 && (g_t_min = t0))
		g_normal = process_normal(ray, cy.dir);
	infinity_cy(ray, cy, &g_normal, &g_t_min);
	if (!(g_t_min > 0 && g_t_min != 10E37))
		return (0);
	i_i->inter = add_vect(ray.o, mult_vect(ray.d, g_t_min));
	i_i->t = g_t_min;
	i_i->normal = g_normal;
	return (1);
}
