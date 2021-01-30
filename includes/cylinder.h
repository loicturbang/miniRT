/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:18:57 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:05:41 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

typedef struct		s_cylinder
{
	t_vector		o;
	t_vector		dir;
	double			ray;
	double			height;
	t_vector		color;
	t_vector		g_t;
	t_vector		g_b;
	double			a;
	double			b;
	double			c;
}					t_cylinder;

#endif
