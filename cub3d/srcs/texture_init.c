/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:30:21 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:19:52 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	create_texture(t_image *image, char *name, t_all *all)
{
	int	h;
	int	w;

	if (all->errors.error)
		return ;
	h = 64;
	w = 64;
	image->ptr = mlx_xpm_file_to_image(all->mlx.mlx, name, &w, &h);
	if (!image->ptr)
		ft_errors(10, all);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->line_size, &image->endian);
}

void	texture_init(t_all *all)
{
	create_texture(&all->scene.north_path,
		all->scene.north_path.directory, all);
	create_texture(&all->scene.south_path,
		all->scene.south_path.directory, all);
	create_texture(&all->scene.east_path,
		all->scene.east_path.directory, all);
	create_texture(&all->scene.west_path,
		all->scene.west_path.directory, all);
	create_texture(&all->scene.sprite_path,
		all->scene.sprite_path.directory, all);
}
