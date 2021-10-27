/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:57:55 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 19:16:31 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list_map	*new_node_map(char *line)
{
	t_list_map	*node;

	node = malloc(sizeof(t_list_map));
	node->data = ft_strdup(line);
	node->next = 0;
	return (node);
}

t_list_map	*push_back_map(t_list_map *list, char *line)
{
	t_list_map	*current;

	if (!list)
		list = new_node_map(line);
	else
	{
		current = list;
		while (current->next)
			current = current->next;
		current->next = new_node_map(line);
	}
	return (list);
}

int	map_create_read(char *line, int fd, t_list_map *list, t_all *all)
{
	int	map_file;

	map_file = get_next_line(fd, &line);
	while (map_file > 0)
	{
		if (*line == '\n' || *line == '\0')
			break ;
		list = push_back_map(list, line);
		free(line);
		map_file = get_next_line(fd, &line);
	}
	list = push_back_map(list, line);
	free(line);
	if (map_file < 0)
		ft_errors(8, all);
	return (map_file);
}

void	map_create(char *line, int fd, t_all *all)
{
	int			map_file;
	t_list_map	*list;

	list = 0;
	list = push_back_map(list, line);
	map_file = map_create_read(line, fd, list, all);
	if (map_file > 0)
	{
		map_file = get_next_line(fd, &line);
		while (map_file > 0)
		{
			free(line);
			if (*line != '\n' && *line != '\0')
				ft_errors(5, all);
			line = 0;
			map_file = get_next_line(fd, &line);
		}
	}
	map_create_all(list, all);
}
