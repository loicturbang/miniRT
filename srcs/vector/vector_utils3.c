/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:42:09 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:16:41 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_vector	cross(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_vector	process_normal(t_ray ray, t_vector normal)
{
	double		res;
	t_vector	tmp;

	res = dot_vect(ray.d, normal);
	if (res < 0)
		return (normal);
	tmp = inverse_vect(normal);
	return (tmp);
}
