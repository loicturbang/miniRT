/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:07:12 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:06:46 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct		s_img
{
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*data;
}					t_img;

#endif
