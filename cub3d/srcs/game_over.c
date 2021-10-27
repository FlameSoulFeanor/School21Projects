/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:51:32 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 19:02:55 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_error(t_all *all)
{
	if (all->errors.error && all->errors.error_args)
		ft_putstr("Error: ARGUMENTS ERROR!!!\n");
	if (all->errors.error && all->errors.error_read)
		ft_putstr("Error: READ ERROR!!!\n");
	if (all->errors.error && all->errors.error_memory)
		ft_putstr("Error: MEMORY ERROR!!!\n");
	if (all->errors.error && all->errors.error_map)
		ft_putstr("Error: MAP ERROR!!!\n");
	if (all->errors.error && all->errors.error_mlx)
		ft_putstr("Error: MLX ERROR!!!\n");
	if (all->errors.error && all->errors.error_config)
		ft_putstr("Error: CONFIGURATION ERROR!!!\n");
	if (all->errors.error && all->errors.error_texture)
		ft_putstr("Error: TEXTURE ERROR!!!\n");
	if (all->errors.error && all->errors.error_resolution)
		ft_putstr("Error: RESOLUTION ERROR\n");
	if (all->errors.error && all->errors.error_floor)
		ft_putstr("Error: FLOOR ERROR!!!\n");
	if (all->errors.error && all->errors.error_ceil)
		ft_putstr("Error: CEIL ERROR!!!\n");
}

static void	free_list_sprite(t_list_sprite *root)
{
	t_list_sprite	*next;

	next = root;
	while (next)
	{
		next = root->next;
		free(root);
		root = next;
	}
}

void	args_free(t_all *all)
{
	if (all->scene.east_path.directory)
		free(all->scene.east_path.directory);
	if (all->scene.west_path.directory)
		free(all->scene.west_path.directory);
	if (all->scene.north_path.directory)
		free(all->scene.north_path.directory);
	if (all->scene.south_path.directory)
		free(all->scene.south_path.directory);
	if (all->scene.sprite_path.directory)
		free(all->scene.sprite_path.directory);
	if (all->scene.map)
		free(all->scene.map);
	if (all->sprites)
		free_list_sprite(all->sprites);
	if (all->list_dist.list_dist)
		free(all->list_dist.list_dist);
}

void	game_over(t_all *all)
{
	print_error(all);
	args_free(all);
	exit(all->errors.error);
}
