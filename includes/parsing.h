/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 21:07:29 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:18:38 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void				ft_set_res(int *i, char *line, t_scene *scene);
void				ft_set_light(int *i, char *line, t_scene *scene);
void				ft_set_cam(int *i, char *line, t_scene *scene);
int					ft_add_obj(t_scene *scene, t_object *obj);
void				ft_set_sphere(int *i, char *line, t_scene *scene);
void				ft_set_plane(int *i, char *line, t_scene *scene);
void				ft_set_square(int *i, char *line, t_scene *scene);
void				ft_set_triangle(int *i, char *line, t_scene *scene);
void				ft_set_cyl(int *i, char *line, t_scene *scene);
void				ft_set_spot(int *i, char *line, t_scene *scene);
void				show_error(char *error_string, char *type);
int					ft_check_vector(t_vector vector, double min, double max);

#endif
