/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:20:30 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:34:02 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

t_vector		vector(double x, double y, double z);
t_vector		add_vect(t_vector v1, t_vector v2);
t_vector		sub_vect(t_vector v1, t_vector v2);
t_vector		mult_vect(t_vector v1, double i);
t_vector		mult_2vect(t_vector v1, t_vector v2);
t_vector		div_vect(t_vector v1, double i);
t_vector		normalize_vect(t_vector v1);
t_vector		inverse_vect(t_vector v);
t_vector		cross(t_vector a, t_vector b);
double			dot_vect(t_vector v1, t_vector v2);
double			norm2_vect(t_vector v1);
void			rot(t_vector *vect, t_vector *angle);
t_vector		apply_rot(t_vector pos, t_vector dir, t_vector rot);

#endif
