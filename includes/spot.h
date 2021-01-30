/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:13:24 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:32:27 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOT_H
# define SPOT_H

typedef struct		s_spot
{
	t_vector		origin;
	double			intensity;
	t_vector		color;
	struct s_spot	*next;
}					t_spot;

#endif
