/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:46:56 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/31 08:29:07 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void		ft_set_res(int *i, char *line, t_scene *scene)
{
	*i += 1;
	if (scene->resx != 0)
		show_error("SET > 1 !\n", "RES: ");
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <R> instead\n", "RES: ");
	next_whitespace(i, line);
	scene->resx = mini_atoi(line, i, "RES: ");
	next_whitespace(i, line);
	scene->resy = mini_atoi(line, i, "RES: ");
	next_whitespace(i, line);
	if (line[*i] || scene->resx <= 0 || scene->resy <= 0)
		show_error("BAD VALUE - use <resx resy> '> 0' instead\n", "RES: ");
	if (scene->resx > LIMIT_RES_X)
		scene->resx = LIMIT_RES_X;
	if (scene->resy > LIMIT_RES_Y)
		scene->resy = LIMIT_RES_Y;
}

void		ft_set_light(int *i, char *line, t_scene *scene)
{
	*i += 1;
	if (scene->light.intensity != -1)
		show_error("SET > 1 !\n", "AMBIENT LIGHT: ");
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <A> instead\n", "AMBIENT LIGHT: ");
	next_whitespace(i, line);
	scene->light.intensity = mini_atoi_d(line, i, "AMBIENT LIGHT: ");
	if (mini_atoi_vector(line, i, &scene->light.color, "AMBIENT LIGHT: ") == -1)
		show_error("BAD VALUE - use <A intensity red,green,blue> instead\n", \
"AMBIENT LIGHT: ");
	next_whitespace(i, line);
	if (scene->light.intensity < 0.0 || scene->light.intensity > 1.0)
		show_error("BAD VALUE - intensity must be between 0.0-1.0", \
"AMBIENT LIGHT: ");
	if (ft_check_vector(scene->light.color, 0, 255) == -1)
		show_error("BAD VALUE - color must be between 0-255 => \
'red,green,blue'", "AMBIENT LIGHT: ");
}

static int	ft_add_cam(t_scene *scene, t_cam *cam)
{
	t_cam *start;

	if (!scene->cams)
	{
		if (!(scene->cams = malloc(sizeof(t_cam))))
			return (-1);
		scene->cams = cam;
		return (1);
	}
	start = scene->cams;
	while (start->next)
		start = start->next;
	start->next = cam;
	return (1);
}

void		ft_set_cam(int *i, char *line, t_scene *scene)
{
	t_cam *cam;

	*i += 1;
	if (!(ft_is_whitespace(line[*i])))
		show_error("BAD PREFIX - use <c> instead\n", "CAMERA: ");
	if (!(cam = malloc(sizeof(t_cam))))
		show_error("error", "MALLOC ALLOCATION: ");
	cam->next = 0;
	if (mini_atoi_d_vector(line, i, &cam->origin, "CAMERA: ") == -1 || \
				mini_atoi_d_vector(line, i, &cam->dir, "CAMERA: ") == -1)
		show_error("BAD VECTOR VALUE - use <c x,y,z  x,y,z  FOV> \
instead\n", "CAMERA: ");
	next_whitespace(i, line);
	cam->fov = mini_atoi(line, i, "CAMERA: ");
	if (ft_check_vector(cam->dir, -1.0, 1.0) == -1)
		show_error("BAD VALUE - direction must be between -1.0 - 1.0", \
"CAMERA: ");
	if (cam->fov < 0 || cam->fov > 180)
		show_error("BAD VALUE - FOV must be between 0-180", "CAMERA: ");
	scene->nb_cam = scene->nb_cam + 1;
	ft_add_cam(scene, cam);
}

int			ft_add_obj(t_scene *scene, t_object *obj)
{
	t_object *start;

	if (!scene->objs)
	{
		if (!(scene->objs = malloc(sizeof(t_object))))
			return (-1);
		scene->objs = obj;
		return (1);
	}
	start = scene->objs;
	while (start->next)
	{
		start = start->next;
	}
	start->next = obj;
	return (1);
}
