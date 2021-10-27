#include "../includes/so_long.h"

static void	init_type_next(t_all *all, int i, int j)
{
	if (all->tiles[i][j].type == 'C')
	{
		all->collect_count++;
		all->tiles[i][j].color = 0x00D19A66;
		all->tiles[i][j].img = all->collect_img;
	}
	else if (all->tiles[i][j].type == 'P')
	{
		all->tiles[i][j].type = '0';
		all->tiles[i][j].color = 0x00636D83;
		all->tiles[i][j].img = all->empty_img;
		all->player.x = j;
		all->player.y = i;
	}
	else if (all->tiles[i][j].type == 'E')
	{
		all->tiles[i][j].color = 0x00F00000;
		all->tiles[i][j].img = all->exit_img;
	}
}

static void	init_type(t_all *all, int i, int j)
{
	if (all->tiles[i][j].type == '0')
	{
		all->tiles[i][j].color = 0x00636D83;
		all->tiles[i][j].img = all->empty_img;
	}
	else if (all->tiles[i][j].type == '1')
	{
		all->tiles[i][j].color = 0x00101010;
		all->tiles[i][j].img = all->wall_img;
	}
	else
		init_type_next(all, i, j);
}

static void	all_init(t_all *all, int sx, int sy)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->scene.map_size_y)
	{
		all->tiles[i] = malloc(sizeof(t_tile) * all->scene.map_size_x);
		j = 0;
		while (j < all->scene.map_size_x)
		{
			all->tiles[i][j].type = all->scene.map[i][j];
			all->tiles[i][j].x = j;
			all->tiles[i][j].y = i;
			init_type(all, i, j);
			all->tiles[i][j].sx = sx;
			all->tiles[i][j].sy = sy;
			j++;
		}
		i++;
	}
}

static t_img	init_img(t_all *all, unsigned int color, int sx, int sy)
{
	t_img	tmp;
	int		i;

	tmp.id = mlx_new_image(all->mlx.mlx, sx, sy);
	tmp.data = (unsigned int *)mlx_get_data_addr(tmp.id, &tmp.bpp, &tmp.line_size,
			&tmp.endian);
	i = 0;
	while (i < sx * sy)
	{
		tmp.data[i] = mlx_get_color_value(all->mlx.mlx, color);
		i++;
	}
	return (tmp);
}

void	more_init(t_all *all)
{
	int	sx;
	int	sy;

	sx = all->scene.x / all->scene.map_size_x;
	sy = all->scene.y / all->scene.map_size_y;
	all->won = 0;
	all->tiles = malloc(sizeof(t_tile *) * all->scene.map_size_y);
	all->empty_img = init_img(all, 0x00636D83, sx, sy);
	all->wall_img = init_img(all, 0x00101010, sx, sy);
	all->collect_img = init_img(all, 0x00D19A66, sx, sy);
	all->player_img = init_img(all, 0x0000F000, sx, sy);
	all->exit_img = init_img(all, 0x00F00000, sx, sy);
	all->player.type = 'P';
	all->player.sx = sx;
	all->player.sy = sy;
	all->player.color = 0x0000F000;
	all->player.img = all->player_img;
	all->collect_count = 0;
	all_init(all, sx, sy);
	window_create(all);
}
 