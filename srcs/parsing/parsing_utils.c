/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:52:15 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:14:21 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void		show_error(char *error_string, char *type)
{
	ft_putstr("Error\n");
	ft_putstr(type);
	ft_putstr(error_string);
	exit(-1);
}

int			ft_check_vector(t_vector vector, double min, double max)
{
	if (vector.x < min || vector.x > max || \
		vector.y < min || vector.y > max || \
		vector.z < min || vector.z > max)
		return (-1);
	else
		return (1);
}
