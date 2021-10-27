/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:19:51 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:21:29 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	north_south_init(char c, t_all *all)
{
	if (c == 'N')
	{
		all->player.x_cam = 0.7;
		all->player.y_cam = 0;
		all->player.x_dir = 0;
		all->player.y_dir = -1;
	}
	if (c == 'S')
	{
		all->player.x_cam = -0.7;
		all->player.y_cam = 0;
		all->player.x_dir = 0;
		all->player.y_dir = 1;
	}
}

static void	east_west_init(char c, t_all *all)
{
	if (c == 'E')
	{
		all->player.x_cam = 0;
		all->player.y_cam = 0.7;
		all->player.x_dir = 1;
		all->player.y_dir = 0;
	}
	if (c == 'W')
	{
		all->player.x_cam = 0;
		all->player.y_cam = -0.7;
		all->player.x_dir = -1;
		all->player.y_dir = 0;
	}
}

void	vectors_init(char c, int i, int j, t_all *all)
{
	all->player.x = j + 0.5;
	all->player.y = i + 0.5;
	north_south_init(c, all);
	east_west_init(c, all);
}
