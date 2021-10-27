/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:56:29 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/16 16:28:21 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	change_pos_1(double val_1, double val_2, t_all *all)
{
	double	step;
	int		coor;

	step = 0.2;
	coor = (int)(all->player.x + step * val_1)
		+ (int)all->player.y * all->scene.map_size.x;
	if (all->scene.map[coor] != '1')
		all->player.x += val_1 * step;
	coor = (int)all->player.x + (int)(all->player.y
			+ step * val_2)*all->scene.map_size.x;
	if (all->scene.map[coor] != '1')
		all->player.y += val_2 * step;
}

static void	change_pos_2(double val_1, double val_2, t_all *all)
{
	double	step;
	int		coor;  

	step = 0.2;
	coor = (int)(all->player.x - step *val_1)
		+ (int)all->player.y * all->scene.map_size.x;
	if (all->scene.map[coor] != '1')
		all->player.x -= val_1 * step;
	coor = (int)all->player.x + (int)(all->player.y
			- step * val_2)*all->scene.map_size.x;
	if (all->scene.map[coor] != '1')
		all->player.y -= val_2 * step;
}

void	change_position(double val_1, double val_2, int mode, t_all *all)
{
	if (mode)
		change_pos_1(val_1, val_2, all);
	else
		change_pos_2(val_1, val_2, all);
}

void	move_player(int key, t_all *all)
{
	if (key == KEY_W)
		change_position(all->player.x_dir, all->player.y_dir,
			1, all);
	if (key == KEY_S)
		change_position(all->player.x_dir, all->player.y_dir,
			0, all);
	if (key == KEY_A)
		change_position(all->player.x_cam, all->player.y_cam,
			0, all);
	if (key == KEY_D)
		change_position(all->player.x_cam, all->player.y_cam,
			1, all);
}
