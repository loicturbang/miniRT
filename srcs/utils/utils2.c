/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:47:52 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:16:04 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void			next_whitespace(int *i, char *line)
{
	while (line[*i] && ((line[*i] >= 9 && line[*i] <= 13) || line[*i] == ' '))
	{
		*i += 1;
	}
}

int				mini_atoi(char *line, int *i, char *type)
{
	int res;
	int neg;

	res = 0;
	neg = 1;
	if (line[*i] == '-')
	{
		neg = -1;
		*i += 1;
	}
	if (!((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '.'))
		show_error("BAD SPACING / NUMBER MISSING / \
							TOO MUCH NUMBERS IN PARAM !\n", type);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		res = (res * 10) + line[*i] - 48;
		*i += 1;
	}
	return (res * neg);
}

int				mini_atoi_vector(char *line, int *i, t_vector *res, char *type)
{
	next_whitespace(i, line);
	res->x = mini_atoi(line, i, type);
	if (line[*i] != ',')
		return (-1);
	*i += 1;
	res->y = mini_atoi(line, i, type);
	if (line[*i] != ',')
		return (-1);
	*i += 1;
	res->z = mini_atoi(line, i, type);
	return (1);
}

static void		mini_atoi_d2(char *line, int *i, int *neg)
{
	if (line[*i] == '-')
	{
		*neg = -1;
		*i += 1;
	}
}

double			mini_atoi_d(char *line, int *i, char *type)
{
	double	res;
	int		neg;
	double	mult;

	res = 0;
	neg = 1;
	mult = 1;
	mini_atoi_d2(line, i, &neg);
	if (!((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '.'))
		show_error("BAD SPACING / NUMBER MISSING / TOO MUCH \
									NUMBERS IN PARAM !\n", type);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		res = (res * 10) + line[*i] - 48;
		*i += 1;
	}
	if (line[*i] == '.')
		*i += 1;
	while (line[*i] >= '0' && line[*i] <= '9' && (mult *= 10.0))
	{
		res += (line[*i] - 48) / mult;
		*i += 1;
	}
	return (res * neg);
}
