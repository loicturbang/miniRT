/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:59:09 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/31 08:22:22 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static t_vector	ft_init_vect(void)
{
	t_vector ret;

	ret.x = -1;
	ret.y = -1;
	ret.z = -1;
	return (ret);
}

static void		ft_init(t_scene *scene)
{
	scene->resx = 0;
	scene->resy = 0;
	scene->light.intensity = -1;
	scene->light.color = ft_init_vect();
	scene->objs = 0;
	scene->cams = 0;
	scene->spots = 0;
	scene->nb_cam = 0;
}

int				main(int argc, char **argv)
{
	t_scene scene;

	ft_init(&scene);
	ft_parsing(argc, argv, &scene);
	if (argc == 2)
		ft_init_window(&scene);
	if (argc == 3)
	{
		scene.img = NULL;
		scene.actual_cam = scene.cams;
		scene.mlx_ptr = mlx_init();
		ray_tracing(&scene);
		save_img("scenes/bmp/out.bmp", &scene);
	}
	return (1);
}
