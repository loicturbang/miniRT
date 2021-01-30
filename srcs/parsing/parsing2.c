/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:06:04 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/31 08:30:00 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void		ft_set_sphere(int *i, char *line, t_scene *scene)
{
	t_sphere *sphere;
	t_object *object;

	*i += 2;
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <sp> instead\n", "SPHERE: ");
	if (!(object = malloc(sizeof(t_object))))
		show_error("error", "MALLOC ALLOCATION: ");
	if (!(sphere = malloc(sizeof(t_sphere))))
		show_error("error", "MALLOC ALLOCATION: ");
	object->next = 0;
	object->type = 'p';
	if (mini_atoi_d_vector(line, i, &sphere->o, "SPHERE: ") == -1)
		show_error("BAD ORIGIN VALUE - use <sp x,y,z ray red,green,blue> \
instead\n", "SPHERE: ");
	next_whitespace(i, line);
	sphere->ray = mini_atoi_d(line, i, "SPHERE: ");
	if (mini_atoi_d_vector(line, i, &sphere->color, "SPHERE: ") == -1)
		show_error("BAD COLOR - use <sp x,y,z ray r,g,b> instead\n", "SP: ");
	if (ft_check_vector(sphere->color, 0, 255) == -1)
		show_error("BAD COLOR VALUE - must be between 0-255\n", "SPHERE: ");
	if (sphere->ray < 0.0)
		show_error("BAD RAY VALUE - must be > 0\n", "SPHERE: ");
	object->obj = sphere;
	ft_add_obj(scene, object);
}

void		ft_set_plane(int *i, char *line, t_scene *scene)
{
	t_plane		*plane;
	t_object	*object;

	*i += 2;
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <pl> instead\n", "PLANE: ");
	if (!(object = malloc(sizeof(t_object))))
		show_error("error", "MALLOC ALLOCATION: ");
	if (!(plane = malloc(sizeof(t_plane))))
		show_error("error", "MALLOC ALLOCATION: ");
	*i += 1;
	object->next = 0;
	object->type = 'l';
	if (mini_atoi_d_vector(line, i, &plane->origin, "PLANE: ") == -1 || \
					mini_atoi_d_vector(line, i, &plane->dir, "PLANE: ") == -1)
		show_error("BAD VECTOR - use <pl x,y,z x,y,z r,g,b> instead\n", "PL: ");
	if (mini_atoi_d_vector(line, i, &plane->color, "PLANE: ") == -1)
		show_error("BAD COLOR - use <pl x,y,z x,y,z r,g,b> instead\n", "PL: ");
	if (ft_check_vector(plane->dir, -1, 1) == -1)
		show_error("BAD VECTOR - use <pl x,y,z x,y,z r,g,b> instead\n", "PL: ");
	if (ft_check_vector(plane->color, 0, 255) == -1)
		show_error("BAD COLOR VALUE - must be between 0-255\n", "PLANE: ");
	object->obj = plane;
	ft_add_obj(scene, object);
}

static void	ft_set_square_points(t_square *square)
{
	t_vector vectors[4];

	vectors[0] = vector(square->height / 2, square->height / 2, 0);
	vectors[1] = vector(-square->height / 2, square->height / 2, 0);
	vectors[2] = vector(square->height / 2, -square->height / 2, 0);
	vectors[3] = vector(-square->height / 2, -square->height / 2, 0);
	rot(&vectors[0], &square->dir);
	rot(&vectors[1], &square->dir);
	rot(&vectors[2], &square->dir);
	rot(&vectors[3], &square->dir);
	square->a = add_vect(vectors[0], square->origin);
	square->b = add_vect(vectors[1], square->origin);
	square->c = add_vect(vectors[2], square->origin);
	square->d = add_vect(vectors[3], square->origin);
}

static void	ft_set_square2(int *i, char *line, t_square *sq)
{
	if (mini_atoi_d_vector(line, i, &sq->origin, "SQUARE: ") == -1 \
		|| mini_atoi_d_vector(line, i, &sq->dir, "SQUARE: ") == -1)
		show_error("BAD VECTOR VALUE - use <sq x,y,z x,y,z height \
red,green,blue> instead\n", "SQUARE: ");
	next_whitespace(i, line);
	sq->height = mini_atoi_d(line, i, "SQUARE: ");
	if (mini_atoi_d_vector(line, i, &sq->color, "SQUARE: ") == -1)
		show_error("BAD COLOR VALUE - use <sq x,y,z x,y,z height \
red,green,blue> instead\n", "SQUARE: ");
	if (ft_check_vector(sq->dir, -1, 1) == -1)
		show_error("BAD VECTOR VALUE - direction must be \
between -1.0 - 1.0\n", "SQUARE: ");
	if (ft_check_vector(sq->color, 0, 255) == -1)
		show_error("BAD COLOR VALUE - must be between 0-255\n", "SQUARE: ");
	if (sq->height < 0)
		show_error("BAD HEIGHT - must be > 0\n", "SQUARE: ");
}

void		ft_set_square(int *i, char *line, t_scene *scene)
{
	t_square *square;
	t_object *object;

	*i += 2;
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <sq> instead\n", "SQUARE: ");
	if (!(object = malloc(sizeof(t_object))))
		show_error("error", "MALLOC ALLOCATION: ");
	if (!(square = malloc(sizeof(t_square))))
		show_error("error", "MALLOC ALLOCATION: ");
	*i += 1;
	object->next = 0;
	object->type = 'q';
	ft_set_square2(i, line, square);
	ft_set_square_points(square);
	square->ab = sub_vect(square->b, square->a);
	square->ac = sub_vect(square->c, square->a);
	object->obj = square;
	ft_add_obj(scene, object);
}
