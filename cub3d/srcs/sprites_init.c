/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:23:55 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:15:52 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list_sprite	*new_sprite(t_sprite *data)
{
	t_list_sprite	*node;

	node = malloc(sizeof(t_list_sprite));
	node->sprite.x = data->x;
	node->sprite.y = data->y;
	node->next = 0;
	return (node);
}

t_list_sprite	*push_back_sprites(t_list_sprite *root, t_sprite *data)
{
	t_list_sprite	*current;

	if (!root)
		root = new_sprite(data);
	else
	{
		current = root;
		while (current->next)
			current = current->next;
		current->next = new_sprite(data);
	}
	return (root);
}

void	sprites_init(t_all *all)
{
	int			i;
	int			j;
	char		c;
	t_sprite	sprite;

	i = 0;
	j = 0;
	all->sprites = 0;
	while (i < all->scene.map_size.y)
	{
		j = 0;
		while (j < all->scene.map_size.x)
		{
			c = all->scene.map[j + i * all->scene.map_size.x];
			if (c == '2')
			{
				sprite.x = j;
				sprite.y = i;
				all->sprites = push_back_sprites(all->sprites, &sprite);
			}
			j++;
		}
		i++;
	}
}
