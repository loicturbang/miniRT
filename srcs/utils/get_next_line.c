/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:45:20 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:15:55 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_free(char **tofree, int ret)
{
	if (*tofree)
	{
		free(*tofree);
		*tofree = 0;
	}
	return (ret);
}

static int	ft_check_nl(char *str)
{
	unsigned int i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == '\n')
			{
				return (1);
			}
			i++;
		}
	return (0);
}

static int	ft_setline(char **save, char **line, int ret)
{
	unsigned int	i;
	char			*temp;

	i = ft_gnl_strchr(*save, '\n') - *save;
	temp = *save;
	*line = ft_gnl_sub(temp, 0, i, &ret);
	if (ret == -1)
		return (-1);
	*save = ft_gnl_sub(temp, i + 1, ft_gnl_strlen(temp), &ret);
	if (ret == -1)
		return (-1);
	if (ret > 0)
		ret = 1;
	return (ft_free(&temp, ret));
}

static int	ft_read_file(char **line, int fd, char **save, int *error)
{
	int				ret;
	char			buff[30];
	char			*temp;

	while ((ret = read(fd, buff, 29)) > 0)
	{
		buff[ret] = '\0';
		temp = *save;
		*save = ft_gnl_strjoin(temp, (char *)buff, error);
		if (*error == -1)
			return (-1);
		free(temp);
		if (ft_check_nl(*save))
			return (ft_setline(save, line, ret));
	}
	if (ret > 0)
		ret = 1;
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char		*save;
	int				ret;
	int				error;

	error = 1;
	if (!line || fd < 0)
		return (-1);
	if (save && ft_check_nl(save))
		return (ft_setline(&save, line, 1));
	ret = ft_read_file(line, fd, &save, &error);
	if (ret == 0 && save == NULL)
	{
		line[0] = ft_gnl_strdup("", &error);
		if (error == -1)
			return (-1);
		return (0);
	}
	if (ret == 0 && save)
	{
		*line = ft_gnl_strdup(save, &ret);
		return (ft_free(&save, ret));
	}
	return (ret);
}
