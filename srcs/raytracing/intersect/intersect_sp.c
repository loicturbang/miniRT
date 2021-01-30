/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 07:41:17 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:33 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	inter_sp2(t_ray ray, t_sphere s, double *t1, double *t2)
{
	double a;
	double b;
	double c;
	double delta;

	a = 1;
	b = 2 * dot_vect(ray.d, sub_vect(ray.o, s.o));
	c = norm2_vect((sub_vect(ray.o, s.o))) - s.ray * s.ray;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	*t1 = (-b - sqrt(delta)) / (2 * a);
	*t2 = (-b + sqrt(delta)) / (2 * a);
	return (1);
}

int			inter_sp(t_ray ray, t_sphere s, t_inter_info *i_i)
{
	double t1;
	double t2;
	double t;

	if (inter_sp2(ray, s, &t1, &t2) == 0)
		return (0);
	if (t2 < 0)
		return (0);
	if (t1 > 0)
		t = t1;
	else
		t = t2;
	i_i->t = t;
	i_i->inter = add_vect(ray.o, mult_vect(ray.d, t));
	i_i->normal = normalize_vect(sub_vect(i_i->inter, s.o));
	return (1);
}
