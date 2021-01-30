/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 10:46:18 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:06:32 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_sub(char const *s, unsigned int st, size_t len, int *e);
char	*ft_gnl_strjoin(char const *s1, char const *s2, int *error);
char	*ft_gnl_strdup(const char *src, int *error);

#endif
