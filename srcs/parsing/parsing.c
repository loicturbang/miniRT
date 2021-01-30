/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lturbang <lturbang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:49:33 by lturbang          #+#    #+#             */
/*   Updated: 2020/07/31 08:31:00 by lturbang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_parsing_dispatch2(char *line, t_scene *scene, int *i)
{
	if (line[*i] == 'R')
		ft_set_res(i, line, scene);
	else if (line[*i] == 'A')
		ft_set_light(i, line, scene);
	else if (line[*i] == 'c' && line[*i + 1] == 'y')
		ft_set_cyl(i, line, scene);
	else if (line[*i] == 'c')
		ft_set_cam(i, line, scene);
	else if (line[*i] == 'l')
		ft_set_spot(i, line, scene);
	else if (line[*i] == 's' && line[*i + 1] == 'p')
		ft_set_sphere(i, line, scene);
	else if (line[*i] == 'p' && line[*i + 1] == 'l')
		ft_set_plane(i, line, scene);
	else if (line[*i] == 's' && line[*i + 1] == 'q')
		ft_set_square(i, line, scene);
	else if (line[*i] == 't' && line[*i + 1] == 'r')
		ft_set_triangle(i, line, scene);
	else if (line[*i] == 0)
		next_whitespace(i, line);
	else
		show_error("in .rt file !\n", "BAD PREFIX ");
}

static int	ft_parsing_dispatch(char *line, t_scene *scene)
{
	int i;

	i = 0;
	next_whitespace(&i, line);
	ft_parsing_dispatch2(line, scene, &i);
	next_whitespace(&i, line);
	if (line[i] != 0)
		show_error("in .rt file !\n", "BAD END OF LINE ");
	return (1);
}

static int	ft_check_scene(t_scene *scene)
{
	if (scene->resx == 0 || scene->resy == 0)
		show_error("in .rt file\n", "NO RESOLUTION FOUND ");
	else if (scene->light.intensity == -1)
		show_error("in .rt file\n", "NO AMBIANT LIGHT FOUND ");
	else if (!scene->cams)
		show_error("in .rt file\n", "NO CAMERA FOUND ");
	return (1);
}

static int	check_extension(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'r' && \
					str[i + 2] == 't' && str[i + 3] == 0)
			return (1);
		i++;
	}
	return (0);
}

int			ft_parsing(int argc, char **argv, t_scene *scene)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	if (argc < 2 || argc > 3)
		show_error("- use ./miniRT <.rt file> <--save (option)>\n", \
											"BAD NUMBER OF PARAMS ");
	if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		show_error("- use ./miniRT <.rt file> <--save (option)>\n", \
												"BAD OPTION ");
	if (!(check_extension(argv[1])))
		show_error("- use ./miniRT <.rt file> <--save (option)>\n", \
											"BAD FILE EXTENSION ");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		show_error(".rt FILE NOT FOUND\n", "Scene: ");
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		ft_parsing_dispatch(line, scene);
		free(line);
		line = NULL;
	}
	return (ft_check_scene(scene));
}
