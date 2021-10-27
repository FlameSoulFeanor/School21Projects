/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:55:32 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 18:58:59 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	end_game(t_all *all)
{
	if (all->mlx.window)
		mlx_destroy_window(all->mlx.mlx, all->mlx.window);
	if (all->image.ptr)
		mlx_destroy_image(all->mlx.mlx, all->image.ptr);
	args_free(all);
	exit(all->errors.error);
}

static void	move_vector(double *x, double *y, int move)
{
	double	curr_y;
	double	curr_x;

	curr_y = *y;
	curr_x = *x;
	if (move)
	{
		*y = curr_y * cos(10 * PI / 180)
			+ curr_x * sin(10 * PI / 180);
		*x = curr_x * cos(10 * PI / 180)
			- curr_y * sin(10 * PI / 180);
	}
	else
	{
		*y = curr_y * cos(-10 * PI / 180)
			+ curr_x * sin(-10 * PI / 180);
		*x = curr_x * cos(-10 * PI / 180)
			- curr_y * sin(-10 * PI / 180);
	}
}

static void	change_view_player(int key, t_all *all)
{
	if (key == KEY_LA)
	{
		move_vector(&all->player.x_dir, &all->player.y_dir, 0);
		move_vector(&all->player.x_cam, &all->player.y_cam, 0);
	}
	else
	{
		move_vector(&all->player.x_dir, &all->player.y_dir, 1);
		move_vector(&all->player.x_cam, &all->player.y_cam, 1);
	}
}

int	press_close(t_all *all)
{
	end_game(all);
	return (0);
}

int	press_key(int key, t_all *all)
{
	if (key == KEY_ESC)
		end_game(all);
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		move_player(key, all);
	if (key == KEY_LA || key == KEY_RA)
		change_view_player(key, all);
	floor_create(all);
	ceil_create(all);
	cast_all(all);
	if (all->scene.save)
		create_bmp(all);
	mlx_put_image_to_window(all->mlx.mlx,
		all->mlx.window, all->image.ptr, 0, 0);
	return (0);
}
