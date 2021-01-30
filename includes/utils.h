/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 21:10:13 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:33:30 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void				ft_putstr(char *s);
size_t				ft_strlen(char *s);
char				*ft_strrchr(char *s, int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(char *src);
void				next_whitespace(int *i, char *line);
int					mini_atoi(char *line, int *i, char *type);
int					ft_isdigit(int c);
int					ft_is_whitespace(char c);
double				mini_atoi_d(char *line, int *i, char *type);
int					mini_atoi_d_vector(char *line, int *i, \
										t_vector *res, char *type);
int					mini_atoi_vector(char *line, int *i, \
										t_vector *res, char *type);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
float				ft_random(size_t *seed);
int					quit_free(void *param);
void				show_error(char *error_string, char *type);
int					get_next_line(int fd, char **line);

#endif
