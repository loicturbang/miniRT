/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:04:23 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/31 08:12:26 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "vector.h"
# include "sphere.h"
# include "square.h"
# include "plane.h"
# include "image.h"
# include "camera.h"
# include "light.h"
# include "spot.h"
# include "object.h"
# include "triangle.h"
# include "cylinder.h"
# include "scene.h"
# include "window.h"
# include "ray.h"
# include "raytracing.h"
# include "get_next_line.h"
# include "parsing.h"
# include "utils.h"

int					ft_parsing(int agrc, char **argv, t_scene *scene);
void				save_img(char *filename, t_scene *scene);
void				ray_tracing(t_scene *scene);

#endif
