/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:08:56 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:44 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void		closest_inter_info_color2(t_inter_info *closest_inter_info)
{
	t_sphere	*sphere;
	t_plane		*plane;

	if (closest_inter_info->node->type == 'p')
	{
		sphere = (t_sphere *)closest_inter_info->node->obj;
		closest_inter_info->color = set_unit_color(sphere->color);
	}
	else if (closest_inter_info->node->type == 'l')
	{
		plane = (t_plane *)closest_inter_info->node->obj;
		closest_inter_info->color = set_unit_color(plane->color);
	}
}

static void		closest_inter_info_color(t_inter_info *closest_inter_info)
{
	t_square	*square;
	t_triangle	*triangle;
	t_cylinder	*cylindre;

	closest_inter_info_color2(closest_inter_info);
	if (closest_inter_info->node->type == 'r')
	{
		triangle = (t_triangle *)closest_inter_info->node->obj;
		closest_inter_info->color = set_unit_color(triangle->color);
	}
	else if (closest_inter_info->node->type == 'q')
	{
		square = (t_square *)closest_inter_info->node->obj;
		closest_inter_info->color = set_unit_color(square->color);
	}
	else if (closest_inter_info->node->type == 'y')
	{
		cylindre = (t_cylinder *)closest_inter_info->node->obj;
		closest_inter_info->color = set_unit_color(cylindre->color);
	}
}

static void		indirect_light(t_ray *random_ray, \
			t_inter_info *inter_info, t_scene *scene, t_random r)
{
	t_vector teng1;
	t_vector teng2;
	t_vector random_local;
	t_vector random;

	random_local = vector(cos(2 * M_PI * r.r1) * sqrt(1 - r.r2), \
							sin(2 * M_PI * r.r1) * sqrt(1 - r.r2), sqrt(r.r2));
	random = vector(ft_random(&scene->seed_final) - 0.5, \
	ft_random(&scene->seed_final) - 0.5, ft_random(&scene->seed_final) - 0.5);
	teng1 = normalize_vect(cross(inter_info->normal, random));
	teng2 = cross(teng1, inter_info->normal);
	random_ray->d = add_vect(mult_vect(inter_info->normal, random_local.z), \
add_vect(mult_vect(teng1, random_local.x), mult_vect(teng2, random_local.y)));
	random_ray->o = add_vect(inter_info->inter, \
										mult_vect(inter_info->normal, 0.001));
}

static void		closest_object(t_object *object, \
		t_inter_info *closest_inter_info, t_inter_info *inter_info, t_ray ray)
{
	double	distance;
	double	tmp_distance;
	int		has_inter;

	distance = 1E99;
	while (object)
	{
		intersect(object, ray, inter_info, &has_inter);
		if (has_inter)
		{
			tmp_distance = norm2_vect(sub_vect(inter_info->inter, ray.o));
			if (tmp_distance < distance)
			{
				distance = tmp_distance;
				closest_inter_info->node = object;
				closest_inter_info->normal = inter_info->normal;
				closest_inter_info->inter = inter_info->inter;
				closest_inter_info->t = inter_info->t;
			}
		}
		object = object->next;
	}
}

t_vector		loop_color(t_object *object, t_ray ray, \
							t_loop_color *lc, t_scene *scene)
{
	t_vector	final_color;
	t_random	r;
	t_ray		random_ray;

	if (lc->max_bounce == 0)
		return (vector(0, 0, 0));
	closest_object(object, lc->c_i_i, lc->i_i, ray);
	if (lc->c_i_i->node)
	{
		closest_inter_info_color(lc->c_i_i);
		final_color = get_final_color(scene, lc->c_i_i);
		r.r1 = ft_random(&scene->seed_final);
		r.r2 = ft_random(&scene->seed_final);
		indirect_light(&random_ray, lc->i_i, scene, r);
		object = scene->objs;
		lc->c_i_i->node = NULL;
		lc->max_bounce = lc->max_bounce - 1;
		final_color = add_vect(final_color, mult_2vect(loop_color(\
		object, random_ray, lc, scene), set_unit_color(lc->c_i_i->color)));
	}
	else
		return (vector(0, 0, 0));
	return (final_color);
}
