/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:04:33 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:08:45 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	mlx_data_init(t_all *all)
{
	int	x;
	int	y;

	x = all->scene.resol.x;
	y = all->scene.resol.y;
	all->mlx.mlx = mlx_init();
	if (!all->mlx.mlx)
		ft_errors(7, all);
	all->mlx.window = mlx_new_window(all->mlx.mlx,
			x, y, "cub3D");
	if (!all->mlx.window)
		ft_errors(7, all);
}

static void	main_image_init(t_all *all)
{
	all->image.ptr = mlx_new_image(all->mlx.mlx,
			all->scene.resol.x, all->scene.resol.y);
	all->image.data = mlx_get_data_addr(all->image.ptr,
			&all->image.bpp,
			&all->image.line_size,
			&all->image.endian);
}

static int	check_extention(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	return (argv[--len] == 'b' && argv[--len] == 'u'
		&& argv[--len] == 'c' && argv[--len] == '.');
}

static void	more_init(t_all *all)
{
	player_init(all);
	sprites_init(all);
	mlx_data_init(all);
	texture_init(all);
	main_image_init(all);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_struct(&all);
	if (argc < 2 || argc > 3)
		ft_errors(1, &all);
	if (!check_extention(argv[1]))
		ft_errors(1, &all);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		ft_errors(1, &all);
	if (argc == 3)
		all.scene.save = 1;
	create_scene(argv[1], &all);
	if (all.errors.error)
		game_over(&all);
	more_init(&all);
	if (all.errors.error)
		game_over(&all);
	press_key(-5, &all);
	mlx_hook(all.mlx.window, 2, 1, press_key, &all);
	mlx_hook(all.mlx.window, 17, 0, press_close, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
