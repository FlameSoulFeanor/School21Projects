#include "../includes/so_long.h"

static t_tile	*move_1(t_all *all, int key)
{
	if (all->won || ((key == KEY_W) && (all->player.y - 1 < 0))
		|| ((key == KEY_S) && (all->player.y + 1 > all->scene.map_size_y - 1))
		|| ((key == KEY_D) && (all->player.x + 1 > all->scene.map_size_x - 1))
		|| ((key == KEY_A) && (all->player.x - 1 < 0)))
		return (NULL);
	if (key == KEY_W)
		return (&all->tiles[all->player.y - 1][all->player.x]);
	else if (key == KEY_S)
		return (&all->tiles[all->player.y + 1][all->player.x]);
	else if (key == KEY_D)
		return (&all->tiles[all->player.y][all->player.x + 1]);
	else if (key == KEY_A)
		return (&all->tiles[all->player.y][all->player.x - 1]);
	return (NULL);
}

static void	move_2(t_all *all, int key, t_tile *target)
{
	if (target->type == '0')
	{
		if (key == KEY_W)
			all->player.y -= 1;
		else if (key == KEY_S)
			all->player.y += 1;
		else if (key == KEY_D)
			all->player.x += 1;
		else if (key == KEY_A)
			all->player.x -= 1;
	}
	write(1, "player pos: [", 13);
	ft_putnbr_fd(all->player.x, 1);
	write(1, "][", 2);
	ft_putnbr_fd(all->player.y, 1);
	write(1, "]\n", 2);
}

static void	move(t_all *all, int key)
{
	t_tile	*target;

	if (all->won)
		return ;
	target = move_1(all, key);
	if (target->type == 'E')
	{
		all->won = 1;
		target->type = '0';
	}
	if (target->type == '1')
		return ;
	else if (target->type == 'P')
		write(1, "humm, hello ?\n", ft_strlen("humm, hello ?\n"));
	else if (target->type == 'C')
	{
		all->collect_count--;
		target->type = '0';
		target->img = all->empty_img;
	}
	move_2(all, key, target);
}

int	hooks(int key, void *arg)
{
	t_all	*all;
	int i;

	i = 0;
	all = (t_all *)arg;
	if (key == KEY_ESC)
	{
		while (i < all->scene.map_size_y)
		{
			free(all->scene.map[i]);
			i++;
		}
		free(all->scene.map);
		exit(0);
	}
	else if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		move(all, key);
	window_create(all);
	return (key);
}
