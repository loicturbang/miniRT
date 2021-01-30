/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:11:26 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:30:41 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ray_tracing2(t_scene *s, double fov, t_loop_color *lc, t_vector xy)
{
	t_vector		final_color;
	t_ray			rayon;
	t_object		*obj;
	unsigned int	col;

	while (xy.y < s->resy)
	{
		xy.x = 0;
		while (xy.x < s->resx)
		{
			rayon.o = s->actual_cam->origin;
			rayon.d = normalize_vect(vector(xy.x + 0.5 - s->resx / \
					2, xy.y + 0.5 - s->resy / 2, xy.z / (2 * tan(fov / 2))));
			rot(&rayon.d, &s->actual_cam->dir);
			obj = s->objs;
			lc->c_i_i->node = NULL;
			lc->max_bounce = 5;
			final_color = loop_color(obj, rayon, lc, s);
			col = (int)(final_color.x * 255.0) * 65536 + \
			(int)(final_color.y * 255.0) * 256 + (int)(final_color.z * 255.0);
			put_pixel_img(s, s->img, col, vector(xy.x, s->resy - 1 - xy.y, 0));
			xy.x++;
		}
		xy.y++;
	}
}

void		ray_tracing(t_scene *scene)
{
	t_loop_color	lc;
	t_vector		xy;
	double			fov;

	if (!(scene->img = malloc(sizeof(t_img))))
		show_error("error\n", "MALLOC ALLOCATION: ");
	if (!(scene->img->img_ptr = mlx_new_image(scene->mlx_ptr, \
								scene->resx, scene->resy)))
		show_error("mlx error", "IMG CREATION: ");
	if (!(scene->img->data = mlx_get_data_addr(scene->img->img_ptr, \
	&scene->img->bits_per_pixel, &scene->img->size_line, &scene->img->endian)))
		show_error("mlx error", "IMG CREATION: ");
	if (!(lc.i_i = malloc(sizeof(t_inter_info))))
		show_error("error\n", "MALLOC ALLOCATION: ");
	if (!(lc.c_i_i = malloc(sizeof(t_inter_info))))
		show_error("error\n", "MALLOC ALLOCATION: ");
	fov = scene->actual_cam->fov * M_PI / 180;
	xy.y = 0;
	xy.z = scene->resx > scene->resy ? scene->resx : scene->resy;
	ray_tracing2(scene, fov, &lc, xy);
}
