/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:31:10 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 22:01:13 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_up_down_map(int i, char *map, t_all *all)
{
	int	j;

	j = 0;
	while (j < all->scene.map_size.x)
	{
		if (map[j + i * all->scene.map_size.x] == ' ')
			check_space_down(i, j, all);
		j++;
	}
	j = 0;
	while (j < all->scene.map_size.x)
	{
		if (map[j + i * all->scene.map_size.x] == ' ')
			check_space_up(i, j, all);
		j++;
	}
}

void	check_left_right_map(int i, char *map, t_all *all)
{
	int	j;

	j = 0;
	while (j < all->scene.map_size.x)
	{
		if (map[j + i * all->scene.map_size.x] == ' ')
			check_right_space(i, j, all);
		j++;
	}
	j = 0;
	while (j < all->scene.map_size.x)
	{
		if (map[j + i * all->scene.map_size.x] == ' ')
			check_left_space(i, j, all);
		j++;
	}
}

int	check_spaces(int i, t_all *all)
{
	int		j;
	int		coor;
	char	*map;

	j = 0;
	map = all->scene.map;
	while (j < all->scene.map_size.x)
	{
		coor = j + i * all->scene.map_size.x;
		if (map[coor] != ' ')
			break ;
		j++;
	}
	if (j == all->scene.map_size.x)
		return (1);
	else
		return (0);
}

void	check_spaces_in_str(int i, t_all *all)
{
	int		j;
	int		coor;
	int		coor_next;
	char	*map;

	map = all->scene.map;
	if (i != 0 && i != all->scene.map_size.y - 1)
	{
		j = 0;
		while (j < all->scene.map_size.x)
		{
			coor = j + (i - 1) * all->scene.map_size.x;
			coor_next = j + (i + 1) * all->scene.map_size.x;
			if (map[coor] != '1' || map[coor_next] != '1')
				ft_errors(5, all);
			j++;
		}
	}
}

void	check_map_in_empty(int i, char *map, t_all *all)
{
	int	j;

	j = 0;
	while (map[j + i * all->scene.map_size.x] == ' '
		&& j < all->scene.map_size.x -1)
		j++;
	if (map[j + i * all->scene.map_size.x] != '1')
		ft_errors(5, all);
	j = all->scene.map_size.x - 1;
	while (map[j + i * all->scene.map_size.x] != '1')
		j--;
	if (map[j + i * all->scene.map_size.x] != '1')
		ft_errors(5, all);
}
