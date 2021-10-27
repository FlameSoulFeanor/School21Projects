#include "../includes/so_long.h"

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
}

// void	args_free(t_all *all)
// {

// }

void	game_over(t_all *all)
{
	print_error(all);
	//args_free(all);
	exit(1);
}

void	errors(int id, t_all *all)
{
	all->errors.error = 1;
	if (id == 1)
		all->errors.error_args = 1;
	if (id == 4)
		all->errors.error_config = 1;
	if (id == 5)
		all->errors.error_map = 1;
	if (id == 6)
		all->errors.error_memory = 1;
	if (id == 7)
		all->errors.error_mlx = 1;
	if (id == 8)
		all->errors.error_read = 1;
	game_over(all);
}
