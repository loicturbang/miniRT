/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:08:59 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:16:33 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_vector	vector(double x, double y, double z)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector	add_vect(t_vector v1, t_vector v2)
{
	t_vector ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;
	return (ret);
}

t_vector	sub_vect(t_vector v1, t_vector v2)
{
	t_vector ret;

	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;
	return (ret);
}

t_vector	mult_vect(t_vector v1, double i)
{
	t_vector ret;

	ret.x = v1.x * i;
	ret.y = v1.y * i;
	ret.z = v1.z * i;
	return (ret);
}

t_vector	mult_2vect(t_vector v1, t_vector v2)
{
	t_vector ret;

	ret.x = v1.x * v2.x;
	ret.y = v1.y * v2.y;
	ret.z = v1.z * v2.z;
	return (ret);
}
