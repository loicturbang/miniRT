/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:25:33 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:14:49 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_vector	no_spot_ambi(t_inter_info *inter_info, t_scene *scene)
{
	t_vector tmp_ambi_color;
	t_vector tmp_inter_color;
	t_vector ret_color;

	tmp_inter_color = mult_vect(inter_info->color, scene->light.intensity);
	tmp_ambi_color = mult_vect(set_unit_color(scene->light.color), \
										(scene->light.intensity / 4.));
	ret_color = div_vect(add_vect(tmp_ambi_color, tmp_inter_color), 2);
	return (ret_color);
}

void		intersect2(t_object *object, t_ray ray, \
										t_inter_info *i_i, int *has_inter)
{
	t_sphere	*sphere;
	t_plane		*plane;

	if (object->type == 'p')
	{
		sphere = (t_sphere *)object->obj;
		*has_inter = inter_sp(ray, *sphere, i_i);
	}
	if (object->type == 'l')
	{
		plane = (t_plane *)object->obj;
		*has_inter = inter_pl(ray, *plane, i_i);
	}
}

void		intersect(t_object *object, t_ray ray, \
										t_inter_info *i_i, int *has_inter)
{
	t_triangle	*triangle;
	t_square	*square;
	t_cylinder	*cyl;

	if (object->type == 'r')
	{
		triangle = (t_triangle *)object->obj;
		*has_inter = inter_tr(ray, *triangle, i_i);
	}
	if (object->type == 'q')
	{
		square = (t_square *)object->obj;
		*has_inter = inter_sq(ray, *square, i_i);
	}
	if (object->type == 'y')
	{
		cyl = (t_cylinder *)object->obj;
		*has_inter = inter_cy(ray, *cyl, i_i);
	}
	intersect2(object, ray, i_i, has_inter);
}

void		trough_obj(int *l_bloc, t_inter_info *i_i, t_spot *spot, t_scene *s)
{
	t_ray			light_ray;
	t_object		*object;
	t_inter_info	inter_info_spot;
	int				has_inter;
	t_light_dist	dist;

	dist.light_to_obj_dist = norm2_vect(sub_vect(i_i->inter, spot->origin));
	light_ray.o = spot->origin;
	light_ray.d = normalize_vect(sub_vect(i_i->inter, spot->origin));
	object = s->objs;
	while (object)
	{
		if (object != i_i->node)
		{
			intersect(object, light_ray, &inter_info_spot, &has_inter);
			if (has_inter)
			{
				dist.light_to_inter_dist = norm2_vect(sub_vect(\
						inter_info_spot.inter, spot->origin)) + EPSILON;
				if (dist.light_to_inter_dist < dist.light_to_obj_dist)
					*l_bloc = 1;
			}
		}
		object = object->next;
	}
}

t_vector	get_final_color(t_scene *scene, t_inter_info *inter_info)
{
	t_spot		*spot;
	int			light_blocked;
	t_vector	final_color;
	t_vector	tmp_ambi_color;

	final_color = vector(0, 0, 0);
	spot = scene->spots;
	tmp_ambi_color = mult_vect(set_unit_color(scene->light.color), \
							(scene->light.intensity / 4.));
	if (!spot)
		return (no_spot_ambi(inter_info, scene));
	while (spot)
	{
		light_blocked = 0;
		trough_obj(&light_blocked, inter_info, spot, scene);
		if (!light_blocked)
			final_color = add_vect(final_color, get_light_at(inter_info, spot));
		spot = spot->next;
	}
	if (scene->light.intensity > 0.0)
		final_color = div_vect(add_vect(tmp_ambi_color, final_color), 2);
	final_color = normalize_color(final_color);
	return (final_color);
}
