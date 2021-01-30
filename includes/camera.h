/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 08:54:15 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:05:27 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct		s_cam
{
	t_vector		origin;
	t_vector		dir;
	int				fov;
	struct s_cam	*next;
}					t_cam;

#endif
