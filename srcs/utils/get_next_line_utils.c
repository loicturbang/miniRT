/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:45:17 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:53 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (s)
		while (str[i])
		{
			if (str[i] == c)
				return (str + i);
			i++;
		}
	return (NULL);
}

char	*ft_gnl_sub(char const *s, unsigned int st, size_t len, int *e)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
	{
		*e = -1;
		return (NULL);
	}
	if (st > ft_gnl_strlen(s))
		return (ft_gnl_strdup("", e));
	if (!(str = malloc(sizeof(char) * (len + 1))))
	{
		*e = -1;
		return (NULL);
	}
	while (s[st] && len-- > 0)
		str[i++] = s[st++];
	str[i] = '\0';
	return (str);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2, int *error)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_gnl_strdup((s2), error));
	if ((!(str = malloc(sizeof(char) * (ft_gnl_strlen(s1)
								+ ft_gnl_strlen(s2) + 1)))))
	{
		*error = -1;
		return (NULL);
	}
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_gnl_strdup(const char *src, int *error)
{
	int					i;
	char				*string;
	unsigned int		size;

	i = 0;
	size = ft_gnl_strlen(src);
	if (!(string = (char *)malloc(sizeof(char) * (size + 1))))
	{
		*error = -1;
		return (NULL);
	}
	while (src[i])
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
