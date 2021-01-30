/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 10:19:34 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:59 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (c == '\0')
		return (s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (j == -1)
		return (NULL);
	return (s + j);
}

int		ft_strcmp(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && i < ft_strlen(s2))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *src)
{
	int					i;
	char				*string;
	unsigned int		size;

	i = 0;
	size = ft_strlen(src);
	if (!(string = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (src[i])
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
