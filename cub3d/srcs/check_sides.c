/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:45:00 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 22:02:22 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_space_down(int i, int j, t_all *all)
{
	char	*map;
	int		coor;

	map = all->scene.map;
	while (i < all->scene.map_size.y)
	{
		coor = j + i * all->scene.map_size.x;
		if (map[coor] != ' ' && map[coor] != '1')
			ft_errors(5, all);
		if (map[coor] == '1')
			break ;
		i++;
	}
}

void	check_space_up(int i, int j, t_all *all)
{
	char	*map;
	int		coor;

	map = all->scene.map;
	while (i >= 0)
	{
		coor = j + i * all->scene.map_size.x;
		if (map[coor] != ' ' && map[coor] != '1')
			ft_errors(5, all);
		if (map[coor] == '1')
			break ;
		i--;
	}	
}

void	check_right_space(int i, int j, t_all *all)
{
	char	*map;
	int		coor;

	map = all->scene.map;
	while (j < all->scene.map_size.x)
	{
		coor = j + i * all->scene.map_size.x;
		if (map[coor] != ' ' && map[coor] != '1')
			ft_errors(5, all);
		if (map[coor] == '1')
			break ;
		j++;
	}
}

void	check_left_space(int i, int j, t_all *all)
{
	char	*map;
	int		coor;

	map = all->scene.map;
	while (j >= 0)
	{
		coor = j + i * all->scene.map_size.x;
		if (map[coor] == '1')
			break ;
		j--;
	}
}
