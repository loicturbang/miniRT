/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:54:34 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:28:18 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# ifndef LIMIT_RES_Y
#  define LIMIT_RES_Y 700
# endif

# ifndef LIMIT_RES_X
#  define LIMIT_RES_X 1000
# endif

typedef struct		s_scene
{
	int				resx;
	int				resy;
	t_light			light;
	t_cam			*cams;
	int				nb_cam;
	t_object		*objs;
	t_spot			*spots;
	t_cam			*actual_cam;
	void			*mlx_ptr;
	void			*mlx_win;
	t_img			*img;
	size_t			seed_final;
	void			**to_free;
}					t_scene;

#endif
