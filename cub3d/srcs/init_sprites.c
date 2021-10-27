/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:24:12 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 22:17:21 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	list_parsing(t_sprite *list, int *range, int list_len, t_all *all)
{
	int				i;
	t_list_sprite	*root;

	i = 0;
	root = all->sprites;
	while (i < list_len)
	{
		list[i].x = root->sprite.x;
		list[i].y = root->sprite.y;
		range[i] = (pow(root->sprite.x - all->player.x, 2)
				+ pow(root->sprite.y - all->player.y, 2));
		root = root->next;
		i++;
	}
}

void	list_sort(t_sprite *list, int *range, int list_len)
{
	int			i;
	int			j;
	int			curr;
	t_sprite	sprite_curr;
	int			min;

	i = 0;
	while (i < list_len - 1)
	{
		j = i + 1;
		min = i;
		while (j < list_len)
		{
			if (range[min] < range[j])
				min = j;
			j++;
		}
		curr = range[i];
		range[i] = range[min];
		range[min] = curr;
		sprite_curr = list[i];
		list[i] = list[min];
		list[min] = sprite_curr;
		i++;
	}
}

void	sprite_calc(t_sprite *sprite, t_var_sprite *var, t_all *all)
{
	double	x_sprite;
	double	y_sprite;

	x_sprite = sprite->x - all->player.x + 0.5;
	y_sprite = sprite->y - all->player.y + 0.5;
	var->mult_const = 1.0 / (all->player.y_dir * all->player.x_cam
			- all->player.x_dir * all->player.y_cam);
	var->x_cast = (x_sprite * all->player.y_dir
			- y_sprite * all->player.x_dir) * var->mult_const;
	var->y_cast = (y_sprite * all->player.x_cam
			+ x_sprite * -all->player.y_cam) * var->mult_const;
	var->dist = fabs(all->scene.resol.y / var->y_cast);
	var->middle = (1 + var->x_cast / var->y_cast)
		* (all->scene.resol.x / 2);
}

void	more_calc(t_var_sprite *var, t_all *all)
{
	var->y_launch = all->scene.resol.y / 2 - var->dist / 2;
	var->x_launch = var->middle - var->dist / 2;
	var->x_finish = var->middle + var->dist / 2;
	var->y_finish = all->scene.resol.y / 2 + var->dist / 2;
	if (0 > var->y_launch)
		var->y_launch = 0;
	if (0 > var->x_launch)
		var->x_launch = 0;
	if (all->scene.resol.y <= var->y_finish)
		var->y_finish = all->scene.resol.y - 1;
	if (all->scene.resol.x <= var->x_finish)
		var->x_finish = all->scene.resol.x - 1;
}
