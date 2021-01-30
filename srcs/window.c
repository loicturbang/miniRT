/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:51:10 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:31:22 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void		put_pixel_img(t_scene *scene, t_img *img, unsigned int color, \
														t_vector pixel_pos)
{
	int (*tab)[scene->resx][1];

	tab = (void *)img->data;
	*tab[(int)pixel_pos.y][(int)pixel_pos.x] = color;
}

static int	gere_key(int keycode, void *param)
{
	t_scene *scene;

	scene = (t_scene *)param;
	if (keycode == 65307)
		quit_free(param);
	else if (keycode == 99 && scene->nb_cam > 1)
	{
		if (scene->actual_cam->next)
			scene->actual_cam = scene->actual_cam->next;
		else
			scene->actual_cam = scene->cams;
		ray_tracing(scene);
		mlx_clear_window(scene->mlx_ptr, scene->mlx_win);
		mlx_put_image_to_window(scene->mlx_ptr, scene->mlx_win, \
											scene->img->img_ptr, 0, 0);
	}
	return (0);
}

static int	expose_hook(void *param)
{
	t_scene *scene;

	scene = (t_scene *)param;
	if (scene->img)
		mlx_put_image_to_window(scene->mlx_ptr, scene->mlx_win, \
											scene->img->img_ptr, 0, 0);
	else
	{
		ray_tracing(scene);
		mlx_clear_window(scene->mlx_ptr, scene->mlx_win);
		mlx_put_image_to_window(scene->mlx_ptr, scene->mlx_win, \
											scene->img->img_ptr, 0, 0);
	}
	return (0);
}

void		ft_init_window(t_scene *scene)
{
	void *seed;

	if (!(seed = malloc(1)))
		show_error("error", "MALLOC ALLOCATION: ");
	scene->to_free = &seed;
	scene->seed_final = (size_t)seed;
	scene->actual_cam = scene->cams;
	scene->mlx_ptr = mlx_init();
	scene->mlx_win = mlx_new_window(scene->mlx_ptr, scene->resx, \
											scene->resy, "mini");
	mlx_clear_window(scene->mlx_ptr, scene->mlx_win);
	scene->img = NULL;
	ray_tracing(scene);
	mlx_put_image_to_window(scene->mlx_ptr, scene->mlx_win, \
										scene->img->img_ptr, 0, 0);
	mlx_key_hook(scene->mlx_win, &gere_key, scene);
	mlx_hook(scene->mlx_win, 17, (1L << 17), &quit_free, scene);
	mlx_expose_hook(scene->mlx_win, &expose_hook, scene);
	mlx_loop(scene->mlx_ptr);
}
