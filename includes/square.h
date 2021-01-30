/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 08:30:32 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:32:40 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

typedef struct		s_square
{
	t_vector		origin;
	t_vector		dir;
	double			height;
	t_vector		color;
	t_vector		a;
	t_vector		b;
	t_vector		c;
	t_vector		d;
	t_vector		ab;
	t_vector		ac;
	double			alpha;
	double			beta;
}					t_square;

#endif
