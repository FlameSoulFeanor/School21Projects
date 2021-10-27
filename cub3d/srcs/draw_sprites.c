/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:04:51 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 18:39:28 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	more_paint(t_var_sprite *var, int i, int j, t_all *all)
{
	int	y_text;
	int	x_text;

	x_text = 64 / var->dist * (i - (var->middle - var->dist / 2));
	y_text = 64 / var->dist * (j - (all->scene.resol.y - var->dist) / 2);
	if (all->scene.sprite_path.data[4 * x_text
			+ all->ray.texture->line_size * y_text])
	{
		all->image.data[4 * i + j * all->image.line_size]
			= all->scene.sprite_path.data[4 * x_text
			+ all->ray.texture->line_size * y_text];
		all->image.data[4 * i + j * all->image.line_size + 1]
			= all->scene.sprite_path.data[4 * x_text
			+ all->ray.texture->line_size * y_text + 1];
		all->image.data[4 * i + j * all->image.line_size + 2]
			= all->scene.sprite_path.data[4 * x_text
			+ all->ray.texture->line_size * y_text + 2];
		all->image.data[4 * i + j * all->image.line_size + 3]
			= all->scene.sprite_path.data[4 * x_text
			+ all->ray.texture->line_size * y_text + 3];
	}
}

static void	paint(t_var_sprite *var, t_all *all)
{
	int	i;
	int	j;
	int	x_text;

	i = var->x_launch;
	while (i < var->x_finish)
	{
		x_text = 64 / var->dist * (i - (var->middle - var->dist / 2));
		if (var->y_cast < all->list_dist.list_dist[i]
			&& var->y_cast > 0 && i > 0 && i < all->scene.resol.x)
		{
			j = var->y_launch + 2;
			while (j < var->y_finish)
			{
				more_paint(var, i, j, all);
				j++;
			}
		}
		i++;
	}
}

static void	paint_sprites(int list_len, t_all *all)
{
	int				i;
	int				*range;
	t_sprite		*list;
	t_var_sprite	var;

	i = 0;
	list = malloc(sizeof(t_sprite) * list_len);
	if (!list)
		ft_errors(6, all);
	range = malloc(sizeof(int) * list_len);
	if (!range)
		ft_errors(6, all);
	list_parsing(list, range, list_len, all);
	list_sort(list, range, list_len);
	while (i < list_len)
	{
		sprite_calc(&list[i], &var, all);
		more_calc(&var, all);
		paint(&var, all);
		i++;
	}
	free(list);
	free(range);
}

static int	count_sprites(t_list_sprite *root)
{
	int	count;

	count = 0;
	if (!root)
		return (0);
	while (root)
	{
		count++;
		root = root->next;
	}
	return (count);
}

void	draw_sprites(t_all *all)
{
	int	list_len;

	list_len = count_sprites(all->sprites);
	if (list_len)
		paint_sprites(list_len, all);
}
