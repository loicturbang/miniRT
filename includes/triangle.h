/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:22:08 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:32:47 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

typedef struct		s_triangle
{
	t_vector		p1;
	t_vector		p2;
	t_vector		p3;
	t_vector		color;
	double			a;
	double			f;
	double			v;
	double			u;
}					t_triangle;

#endif
