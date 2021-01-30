/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:26:44 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/31 08:30:38 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void			ft_set_triangle(int *i, char *line, t_scene *scene)
{
	t_triangle	*triangle;
	t_object	*object;

	*i += 2;
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <tr> instead\n", "TRIANGLE: ");
	if (!(object = malloc(sizeof(t_object))))
		show_error("error", "MALLOC ALLOCATION: ");
	if (!(triangle = malloc(sizeof(t_triangle))))
		show_error("error", "MALLOC ALLOCATION: ");
	*i += 1;
	object->next = 0;
	object->type = 'r';
	if (mini_atoi_d_vector(line, i, &triangle->p1, "TRIANGLE: ") == -1 || \
		mini_atoi_d_vector(line, i, &triangle->p2, "TRIANGLE: ") == -1
			|| mini_atoi_d_vector(line, i, &triangle->p3, "TRIANGLE: ") == -1)
		show_error("BAD VECTOR VALUE - use <tr x,y,z x,y,z x,y,z \
red,green,blue> instead\n", "TRIANGLE: ");
	if (mini_atoi_d_vector(line, i, &triangle->color, "TRIANGLE: ") == -1)
		show_error("BAD COLOR VALUE - use <tr x,y,z x,y,z x,y,z \
red,green,blue> instead\n", "TRIANGLE: ");
	if (ft_check_vector(triangle->color, 0, 255) == -1)
		show_error("BAD COLOR VALUE - must be between 0-255\n", "TRIANGLE: ");
	object->obj = triangle;
	ft_add_obj(scene, object);
}

static void		ft_set_cyl2(int *i, char *line, t_cylinder *cyl)
{
	if (mini_atoi_d_vector(line, i, &cyl->o, "CYLINDER: ") == -1 || \
			mini_atoi_d_vector(line, i, &cyl->dir, "CYLINDER: ") == -1)
		show_error("BAD VECTOR VALUE - use <cy x,y,z x,y,z ray height \
red,green,blue> instead\n", "CYLINDER: ");
	next_whitespace(i, line);
	cyl->ray = mini_atoi_d(line, i, "CYLINDER: ");
	next_whitespace(i, line);
	cyl->height = mini_atoi_d(line, i, "CYLINDER: ");
	if (mini_atoi_d_vector(line, i, &cyl->color, "CYLINDER: ") == -1)
		show_error("BAD COLOR VALUE - use <cy x,y,z x,y,z ray height \
red,green,blue> instead\n", "CYLINDER: ");
	if (ft_check_vector(cyl->dir, -1, 1) == -1)
		show_error("BAD VECTOR VALUE - direction must be between -1.0 \
- 1.0\n", "CYLINDER: ");
	if (ft_check_vector(cyl->color, 0, 255) == -1)
		show_error("BAD COLOR VALUE - must be between 0-255\n", "CYLINDER: ");
	if (cyl->height < 0)
		show_error("BAD HEIGHT - must be > 0\n", "CYLINDER: ");
	if (cyl->ray < 0)
		show_error("BAD RAY - must be > 0\n", "CYLINDER: ");
}

void			ft_set_cyl(int *i, char *line, t_scene *scene)
{
	t_cylinder	*cyl;
	t_object	*object;

	*i += 2;
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <cy> instead\n", "CYLINDER: ");
	if (!(object = malloc(sizeof(t_object))))
		show_error("error", "MALLOC ALLOCATION: ");
	if (!(cyl = malloc(sizeof(t_cylinder))))
		show_error("error", "MALLOC ALLOCATION: ");
	*i += 1;
	object->next = 0;
	object->type = 'y';
	ft_set_cyl2(i, line, cyl);
	object->obj = cyl;
	ft_add_obj(scene, object);
}

static int		ft_add_spot(t_scene *scene, t_spot *spot)
{
	t_spot *start;

	if (!scene->spots)
	{
		if (!(scene->spots = malloc(sizeof(t_spot))))
			return (-1);
		scene->spots = spot;
		return (1);
	}
	start = scene->spots;
	while (start->next)
		start = start->next;
	start->next = spot;
	return (1);
}

void			ft_set_spot(int *i, char *line, t_scene *scene)
{
	t_spot *spot;

	*i += 1;
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <l> instead\n", "SPOT: ");
	if (!(spot = malloc(sizeof(t_spot))))
		show_error("error", "MALLOC ALLOCATION: ");
	*i += 1;
	spot->next = 0;
	if (mini_atoi_d_vector(line, i, &spot->origin, "SPOT: ") == -1)
		show_error("BAD ORIGIN VALUE - use <l x,y,z intensity \
							red,green,blue> instead\n", "SPOT: ");
	next_whitespace(i, line);
	spot->intensity = mini_atoi_d(line, i, "SPOT: ");
	if (mini_atoi_d_vector(line, i, &spot->color, "SPOT: ") == -1)
		show_error("BAD COLOR VALUE - use <l x,y,z intensity \
							red,green,blue> instead\n", "SPOT: ");
	if (ft_check_vector(spot->color, 0, 255) == -1)
		show_error("BAD COLOR VALUE - must be between 0-255\n", "SPOT: ");
	if (spot->intensity < 0 || spot->intensity > 1)
		show_error("BAD INTENSITY VALUE - must be between 0.0-1.0\n", "SPOT: ");
	ft_add_spot(scene, spot);
}
