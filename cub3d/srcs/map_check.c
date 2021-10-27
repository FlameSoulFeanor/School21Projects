/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:43:08 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 22:44:27 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	first_last_check(int i, t_all *all)
{
	int		j;
	int		coor;
	char	*current;

	j = 0;
	current = all->scene.map;
	while (j < all->scene.map_size.x)
	{
		coor = j + i * all->scene.map_size.x;
		if (current[coor] != '1' && current[coor] != ' ')
		{
			all->errors.error = 1;
			all->errors.error_map = 1;
		}
		j++;
	}
}

static int	check_sym(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == ' '
		|| c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

void	check_map_sym(int i, char *map, t_all *all)
{
	int	j;

	j = 0;
	while (j < all->scene.map_size.x)
	{
		if (!check_sym(map[j + i * all->scene.map_size.x]))
		{
			all->errors.error = 1;
			all->errors.error_map = 1;
		}
		j++;
	}
}

void	map_check(t_all *all)
{
	int		i;
	char	*map;

	i = 0;
	map = all->scene.map;
	while (i < all->scene.map_size.y)
	{
		if (!i || i == all->scene.map_size.y - 1)
			first_last_check(i, all);
		else
		{
			if (check_spaces(i, all))
				check_spaces_in_str(i, all);
			else
				check_map_in_empty(i, map, all);
		}
		check_map_sym(i, map, all);
		check_up_down_map(i, map, all);
		check_left_right_map(i, map, all);
		i++;
	}
}
