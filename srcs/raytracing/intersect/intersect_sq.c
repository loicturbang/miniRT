/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:22:15 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:18 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void		inter_sq2(t_ray ray, t_square sq, double *t, t_vector normal)
{
	float denominat;
	float calc;

	*t = 0;
	denominat = -(dot_vect(normal, sq.origin));
	calc = dot_vect(ray.o, normal) + denominat;
	sq.alpha = dot_vect(ray.d, normal);
	*t = -(calc / sq.alpha);
}

int				inter_sq(t_ray ray, t_square sq, t_inter_info *inter_info)
{
	t_vector	point;
	t_vector	ap;
	t_vector	normal;
	double		t;

	normal = normalize_vect(cross(sq.ab, sq.ac));
	inter_sq2(ray, sq, &t, normal);
	if (t <= 0)
		return (0);
	point = add_vect(ray.o, mult_vect(ray.d, t));
	ap = sub_vect(point, sq.a);
	sq.alpha = dot_vect(ap, sq.ab) / dot_vect(sq.ab, sq.ab);
	sq.beta = dot_vect(ap, sq.ac) / dot_vect(sq.ac, sq.ac);
	if (sq.alpha >= 0 && sq.alpha <= 1 && sq.beta >= 0 && sq.beta <= 1)
	{
		inter_info->inter = add_vect(ray.d, mult_vect(ray.o, t));
		inter_info->normal = normal;
		return (1);
	}
	return (0);
}
