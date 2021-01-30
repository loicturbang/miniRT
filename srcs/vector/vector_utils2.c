/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:27:01 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:16:37 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_vector	div_vect(t_vector v1, double i)
{
	t_vector ret;

	ret.x = v1.x / i;
	ret.y = v1.y / i;
	ret.z = v1.z / i;
	return (ret);
}

double		dot_vect(t_vector v1, t_vector v2)
{
	double ret;

	ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (ret);
}

double		norm2_vect(t_vector v1)
{
	double ret;

	ret = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	return (ret);
}

t_vector	normalize_vect(t_vector v1)
{
	t_vector	ret;
	double		norm;

	norm = sqrt(norm2_vect(v1));
	ret.x = v1.x / norm;
	ret.y = v1.y / norm;
	ret.z = v1.z / norm;
	return (ret);
}

t_vector	inverse_vect(t_vector v)
{
	return (mult_vect(v, -1));
}
