/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:50:48 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/14 18:44:16 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	paint_column(int i, int x, t_all *all)
{
	int	y_screen;
	int	y_text;
	int	m_coor;
	int	n_coor;

	y_screen = i - all->scene.resol.y / 2
		+ all->ray.col_height / 2;
	y_text = y_screen * 64 / all->ray.col_height;
	m_coor = i * all->image.line_size + 4 * x;
	n_coor = y_text * all->ray.texture->line_size
		+ 4 * (int)(all->ray.height_wall * 64);
	all->image.data[m_coor] = all->ray.texture->data[n_coor];
	all->image.data[m_coor + 1]
		= all->ray.texture->data[n_coor + 1];
	all->image.data[m_coor + 2]
		= all->ray.texture->data[n_coor + 2];
	all->image.data[m_coor + 3]
		= all->ray.texture->data[n_coor + 3];
}

static void	create_column(int x, t_all *all)
{
	int	i;
	int	end;

	i = all->scene.resol.y / 2 - all->ray.col_height / 2;
	if (i < 0)
		i = 0;
	end = all->scene.resol.y / 2
		+ all->ray.col_height / 2;
	if (end >= all->scene.resol.y)
		end = all->scene.resol.y - 1;
	while (i < end)
	{
		paint_column(i, x, all);
		i++;
	}
}

void	cast_all(t_all *all)
{
	int	x;

	x = 0;
	while (x < all->scene.resol.x)
	{
		all->list_dist.curr = x;
		create_raycasting(x, all);
		step_create(all);
		ray_find(all);
		texture_find(all);
		height_find(all);
		create_column(x, all);
		x++;
	}
	draw_sprites(all);
}
