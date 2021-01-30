/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:17 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:27:50 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# ifndef EPSILON
#  define EPSILON 0.0000001
# endif

typedef struct			s_inter_info
{
	t_object			*node;
	t_vector			color;
	t_vector			inter;
	t_vector			normal;
	double				t;
}						t_inter_info;

typedef struct			s_loop_color
{
	struct s_inter_info	*i_i;
	struct s_inter_info	*c_i_i;
	int					max_bounce;
}						t_loop_color;

typedef struct			s_light_dist
{
	double				light_to_obj_dist;
	double				light_to_inter_dist;
}						t_light_dist;

typedef struct			s_random
{
	double				r1;
	double				r2;
}						t_random;

int						inter_sp(t_ray ray, t_sphere sphere, \
										t_inter_info *inter_info);
int						inter_tr(t_ray ray, t_triangle triangle, \
										t_inter_info *inter_info);
int						inter_pl(t_ray ray, t_plane plane, \
										t_inter_info *inter_info);
int						inter_sq(t_ray ray, t_square square, \
										t_inter_info *inter_info);
int						inter_cy(t_ray ray, t_cylinder cy, \
										t_inter_info *inter_info);
t_vector				process_normal(t_ray ray, \
										t_vector normal);
t_vector				get_final_color(t_scene *scene, \
										t_inter_info *inter_info);
t_vector				get_light_at(t_inter_info *inter_info, \
										t_spot *spot);
t_vector				loop_color(t_object *object, t_ray ray, \
									t_loop_color *lc, t_scene *scene);
void					intersect(t_object *object, t_ray ray, \
									t_inter_info *i_i, int *has_inter);
void					ray_tracing(t_scene *scene);
void					put_pixel_img(t_scene *scene, t_img *img, \
							unsigned int color, t_vector pixel_pos);
t_vector				normalize_color(t_vector color);
t_vector				set_unit_color(t_vector color);

#endif
