#include "../includes/so_long.h"

static int	hook(void)
{
	exit(0);
}

void	init_struct(t_all *all)
{
	all->scene.x = 1920;
	all->scene.y = 1080;
	all->errors.error = 0;
	all->errors.error_memory = 0;
	all->errors.error_args = 0;
	all->errors.error_config = 0;
	all->errors.error_map = 0;
	all->errors.error_mlx = 0;
	all->errors.error_read = 0;
}

static int	check_name(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	return (argv[--len] == 'r' && argv[--len] == 'e'
		&& argv[--len] == 'b' && argv[--len] == '.');
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_struct(&all);
	if (argc < 2 || argc > 3)
		errors(1, &all);
	if (!check_name(argv[1]))
		errors(1, &all);
	create_map(argv[1], &all);
	all.mlx.mlx = mlx_init();
	all.mlx.window = mlx_new_window(all.mlx.mlx, all.scene.x,
			all.scene.y, "so_long");
	mlx_string_put(all.mlx.mlx, all.mlx.window,
		(all.scene.x / 2) - 50, all.scene.y / 2,
		mlx_get_color_value(all.mlx.mlx, 0x00D19A66), "loading...");
	mlx_do_sync(all.mlx.mlx);
	more_init(&all);
	mlx_hook(all.mlx.window, 17, 0, hook, NULL);
	mlx_key_hook(all.mlx.window, hooks, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
