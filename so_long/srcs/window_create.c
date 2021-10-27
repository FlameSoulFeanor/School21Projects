#include "../includes/so_long.h"

static void	won_draw(t_all *all)
{
	if (all->collect_count)
	{
		mlx_string_put(all->mlx.mlx, all->mlx.window,
			(all->scene.x / 2) - 50, all->scene.y / 2,
			mlx_get_color_value(all->mlx.mlx, 0x0000F000), "DEFEAT !!!");
	}
	else
	{
		mlx_string_put(all->mlx.mlx, all->mlx.window,
			(all->scene.x / 2) - 50, all->scene.y / 2,
			mlx_get_color_value(all->mlx.mlx, 0x0000F000), "VICTORY !!!");
	}
}

void	window_create(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->scene.map_size_y)
	{
		j = 0;
		while (j < all->scene.map_size_x)
		{
			if (all->player.x == j && all->player.y == i)
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.window,
					all->player.img.id, all->player.sx * j, all->player.sy * i);
			else
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.window,
					all->tiles[i][j].img.id, all->tiles[i][j].sx * j,
					all->tiles[i][j].sy * i);
			j++;
		}
		i++;
	}
	if (all->won)
		won_draw(all);
}
