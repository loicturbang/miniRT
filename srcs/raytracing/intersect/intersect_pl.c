/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:16:30 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:22 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int		inter_pl(t_ray ray, t_plane plane, t_inter_info *inter_info)
{
	double dot_ray;
	double dot_diff;
	double t;

	dot_diff = dot_vect(sub_vect(ray.o, plane.origin), plane.dir);
	dot_ray = dot_vect(ray.d, plane.dir);
	if (dot_ray == 0 || (dot_diff < 0 && dot_ray < 0) || (dot_diff > 0 \
														&& dot_ray > 0))
		return (0);
	t = -dot_diff / dot_ray;
	if (t < 0.0001)
		return (0);
	inter_info->t = t;
	inter_info->inter = add_vect(ray.o, mult_vect(ray.d, t));
	inter_info->normal = process_normal(ray, plane.dir);
	return (1);
}
