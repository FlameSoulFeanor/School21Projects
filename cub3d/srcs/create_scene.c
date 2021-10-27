/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:44:33 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/13 19:42:49 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	cheack_insert_gl(t_all *all)
{
	return (all->scene.resol.x >= 0
		&& all->scene.resol.y >= 0
		&& all->scene.ceil_clr >= 0
		&& all->scene.floor_clr >= 0
		&& all->scene.east_path.directory
		&& all->scene.west_path.directory
		&& all->scene.north_path.directory
		&& all->scene.south_path.directory
		&& all->scene.sprite_path.directory);
}

static void	pars_line(char *line, t_all *all)
{
	if (line[0] == 'W' || line[0] == 'N' || line[0] == 'E' || line[0] == 'S')
		path_create(line, all);
	else if (line[0] == 'R')
		resolution_create(line, all);
	else if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
		color_create(line, all);
	else if (cheack_insert_gl(all))
		return ;
	else if (*line != '\0')
		ft_errors(1, all);
}

char	*trim_file(int fd, t_all *all)
{
	char	*str;
	int		file;

	str = 0;
	file = get_next_line(fd, &str);
	if (file <= 0)
		ft_errors(8, all);
	while (!str[0])
	{
		free(str);
		file = get_next_line(fd, &str);
		if (file <= 0)
			ft_errors(8, all);
	}
	return (str);
}

static void	end_free(int read_bytes, char *line, t_all *all)
{
	if (read_bytes < 0)
	{
		ft_errors(8, all);
		free(line); 
	}
}

void	create_scene(char *file, t_all *all)
{
	char	*line;
	int		fd;
	int		read_bytes;

	fd = open(file, O_RDONLY);
	line = 0;
	read_bytes = get_next_line(fd, &line);
	while (!cheack_insert_gl(all) && read_bytes > 0)
	{
		pars_line(line, all);
		free(line);
		read_bytes = get_next_line(fd, &line);
	}
	end_free(read_bytes, line, all);
	if (*line != '\0' && *line != '1' && *line != ' ')
		ft_errors(5, all);
	free(line);
	line = trim_file(fd, all);
	map_create(line, fd, all);
	free(line);
	close(fd);
	all->list_dist.list_dist = malloc(sizeof(double)
			* all->scene.resol.x);
	if (!all->list_dist.list_dist)
		ft_errors(6, all);
}
