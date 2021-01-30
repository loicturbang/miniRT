/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:27:09 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:14:54 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_vector	set_unit_color(t_vector color)
{
	t_vector ret;

	ret.x = color.x / 255.0;
	ret.y = color.y / 255.0;
	ret.z = color.z / 255.0;
	return (ret);
}

t_vector	normalize_color(t_vector color)
{
	t_vector ret;

	ret = color;
	if (color.x > 1.0)
		ret.x = 1.0;
	if (color.y > 1.0)
		ret.y = 1.0;
	if (color.z > 1.0)
		ret.z = 1.0;
	return (ret);
}

t_vector	get_light_at(t_inter_info *inter_info, t_spot *spot)
{
	t_vector	light_vect;
	double		angle;
	t_vector	tmp_spot_color;
	t_vector	tmp_inter_color;
	t_vector	ret_color;

	light_vect = sub_vect(inter_info->inter, spot->origin);
	light_vect = normalize_vect(light_vect);
	angle = dot_vect(inter_info->normal, inverse_vect(light_vect));
	tmp_spot_color = mult_vect(set_unit_color(spot->color), spot->intensity);
	tmp_inter_color = mult_vect(inter_info->color, spot->intensity);
	if (angle <= 0)
		ret_color = vector(0, 0, 0);
	else
		ret_color = mult_vect(div_vect(add_vect(tmp_spot_color, \
										tmp_inter_color), 2), angle);
	return (ret_color);
}
