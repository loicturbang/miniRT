/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:35:40 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/30 21:31:05 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static unsigned char	*bmp_file_header(int filesize)
{
	unsigned char *bmpfileheader;

	if (!(bmpfileheader = (unsigned char *)malloc(sizeof(unsigned char) * 14)))
		show_error("error\n", "MALLOC ALLOCATION: ");
	ft_memcpy(bmpfileheader, (char[]){'B', 'M', 0, 0, 0, 0, 0, 0, 0, \
													0, 54, 0, 0, 0}, 14);
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	return (bmpfileheader);
}

static unsigned char	*bmp_info_header(t_scene *scene)
{
	unsigned char *bmpinfoheader;

	if (!(bmpinfoheader = (unsigned char *)malloc(sizeof(unsigned char) * 40)))
		show_error("error\n", "MALLOC ALLOCATION: ");
	ft_memcpy(bmpinfoheader, (char[]){40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
								1, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
								0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 40);
	bmpinfoheader[4] = (unsigned char)(scene->resx);
	bmpinfoheader[5] = (unsigned char)(scene->resx >> 8);
	bmpinfoheader[6] = (unsigned char)(scene->resx >> 16);
	bmpinfoheader[7] = (unsigned char)(scene->resx >> 24);
	bmpinfoheader[8] = (unsigned char)(scene->resy);
	bmpinfoheader[9] = (unsigned char)(scene->resy >> 8);
	bmpinfoheader[10] = (unsigned char)(scene->resy >> 16);
	bmpinfoheader[11] = (unsigned char)(scene->resy >> 24);
	return (bmpinfoheader);
}

static void				data_to_img(int fd, char *data, t_scene *scene)
{
	int	line;

	line = scene->resy;
	while (line)
	{
		write(fd, data + scene->resx * line * 4, scene->resx * 4);
		line--;
	}
}

void					save_img(char *filename, t_scene *scene)
{
	int				file_size;
	int				fd;
	unsigned char	*bmpfileheader;
	unsigned char	*bmpinfoheader;

	file_size = 14 + 40 + 3 * scene->resx * scene->resy;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
	bmpfileheader = bmp_file_header(file_size);
	write(fd, bmpfileheader, 14);
	free(bmpfileheader);
	bmpinfoheader = bmp_info_header(scene);
	write(fd, bmpinfoheader, 40);
	free(bmpinfoheader);
	data_to_img(fd, scene->img->data, scene);
}
