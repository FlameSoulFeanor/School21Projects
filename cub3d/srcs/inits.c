/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:24:32 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 22:20:17 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_all *all)
{
	all->scene.floor_clr = -1;
	all->scene.ceil_clr = -1;
	all->scene.east_path.directory = 0;
	all->scene.west_path.directory = 0;
	all->scene.north_path.directory = 0;
	all->scene.south_path.directory = 0;
	all->scene.sprite_path.directory = 0;
	all->scene.resol.x = -1;
	all->scene.resol.y = -1;
	all->scene.map = 0;
	all->scene.map_size.x = 0;
	all->scene.map_size.y = 0;
	all->errors.error = 0;
	all->errors.error_memory = 0;
	all->errors.error_args = 0;
	all->errors.error_config = 0;
	all->errors.error_ceil = 0;
	all->errors.error_floor = 0;
	all->errors.error_map = 0;
	all->errors.error_mlx = 0;
	all->errors.error_read = 0;
	all->errors.error_resolution = 0;
	all->errors.error_texture = 0;
}

static int	check_player_sym(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

void	player_init(t_all *all)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	all->player.x = -1;
	all->player.y = -1;
	while (i < all->scene.map_size.y)
	{
		j = 0;
		while (j < all->scene.map_size.x)
		{
			c = all->scene.map[j + i * all->scene.map_size.x];
			if (check_player_sym(c))
			{
				if (all->player.x == -1 && all->player.y == -1)
					vectors_init(c, i, j, all);
				else
					ft_errors(5, all);
			}
			j++;
		}
		i++;
	}
}
