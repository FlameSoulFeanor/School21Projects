/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:55:13 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 22:04:34 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	step_create(t_all *all)
{
	if (0 > all->ray.y_ray)
	{
		all->ray.y_step = -1;
		all->ray.y_s = all->ray.y_delta
			* (all->player.y - all->ray.y_map);
	}
	else
	{
		all->ray.y_step = 1;
		all->ray.y_s = all->ray.y_delta
			* (-all->player.y + 1.0 + all->ray.y_map);
	}
	if (0 > all->ray.x_ray)
	{
		all->ray.x_step = -1;
		all->ray.x_s = all->ray.x_delta
			* (all->player.x - all->ray.x_map);
	}
	else
	{
		all->ray.x_step = 1;
		all->ray.x_s = all->ray.x_delta
			* (-all->player.x + 1.0 + all->ray.x_map);
	}
}

void	ray_find(t_all *all)
{
	int	coor;

	while (1)
	{
		if (all->ray.y_s > all->ray.x_s)
		{
			all->ray.x_s += all->ray.x_delta;
			all->ray.x_map += all->ray.x_step;
			all->ray.side = 0;
		}
		else
		{
			all->ray.y_s += all->ray.y_delta;
			all->ray.y_map += all->ray.y_step;
			all->ray.side = 1;
		}
		coor = all->ray.x_map
			+ all->scene.map_size.x * all->ray.y_map;
		if (all->scene.map[coor] == '1')
			break ;
	}
}

void	create_raycasting(int x, t_all *all)
{
	all->ray.vector = -1 + x * 2 / (double)all->scene.resol.x;
	all->ray.x_ray = all->ray.vector
		* all->player.x_cam + all->player.x_dir;
	all->ray.y_ray = all->ray.vector
		* all->player.y_cam + all->player.y_dir;
	all->ray.x_delta = sqrt(1 + pow(all->ray.y_ray, 2)
			/ pow(all->ray.x_ray, 2));
	all->ray.y_delta = sqrt(1 + pow(all->ray.x_ray, 2)
			/ pow(all->ray.y_ray, 2));
	all->ray.x_map = (int)all->player.x;
	all->ray.y_map = (int)all->player.y;
}

void	texture_find(t_all *all)
{
	if (0 < all->ray.x_ray)
	{
		if (all->ray.side)
		{
			if (0 > all->ray.y_ray)
				all->ray.texture = &all->scene.north_path;
			else
				all->ray.texture = &all->scene.south_path;
		}
		else
			all->ray.texture = &all->scene.east_path;
	}
	else
	{
		if (all->ray.side)
		{
			if (0 > all->ray.y_ray)
				all->ray.texture = &all->scene.north_path;
			else
				all->ray.texture = &all->scene.south_path;
		}
		else
			all->ray.texture = &all->scene.west_path;
	}
}

void	height_find(t_all *all)
{
	double	dist;

	if (all->ray.side)
	{
		dist = ((1 - all->ray.y_step) / 2 + all->ray.y_map
				- all->player.y) / all->ray.y_ray;
		all->list_dist.list_dist[all->list_dist.curr] = dist;
		all->ray.col_height = all->scene.resol.y / dist;
		all->ray.height_wall = all->player.x
			+ dist * all->ray.x_ray;
		all->ray.height_wall -= floor(all->ray.height_wall);
	}
	else
	{
		dist = ((1 - all->ray.x_step) / 2 + all->ray.x_map
				- all->player.x) / all->ray.x_ray;
		all->list_dist.list_dist[all->list_dist.curr] = dist;
		all->ray.col_height = all->scene.resol.y / dist;
		all->ray.height_wall = all->player.y
			+ dist * all->ray.y_ray;
		all->ray.height_wall -= floor(all->ray.height_wall);
	}
}
