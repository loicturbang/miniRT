/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:47:54 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:16:11 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int		mini_atoi_d_vector(char *line, int *i, t_vector *res, char *type)
{
	next_whitespace(i, line);
	res->x = mini_atoi_d(line, i, type);
	if (line[*i] != ',')
		return (-1);
	*i += 1;
	res->y = mini_atoi_d(line, i, type);
	if (line[*i] != ',')
		return (-1);
	*i += 1;
	res->z = mini_atoi_d(line, i, type);
	return (1);
}

int		ft_is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dest;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	src = (unsigned char *)s2;
	dest = (unsigned char *)s1;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (s1);
}

float	ft_random(size_t *seed)
{
	unsigned int	result;
	float			ret;

	result = *seed;
	result ^= result << 13;
	result ^= result >> 17;
	result ^= result << 5;
	*seed = result;
	ret = (float)(result / ((float)UINT_MAX + 1));
	return (ret);
}

int		quit_free(void *param)
{
	t_scene *scene;
	void	**temp;

	(void)scene;
	scene = (t_scene *)param;
	temp = scene->to_free;
	free(*temp);
	exit(1);
	return (0);
}
