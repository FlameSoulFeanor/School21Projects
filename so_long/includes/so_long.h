#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx_opengl/mlx.h"
# include "../includes/libft/libft.h"
# include "get_next_line.h"

/*
**	Keys define
*/
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_ESC 53

/*
** Errors processing
*/
typedef struct s_errors
{
	int	error_args;
	int	error_memory;
	int	error_map;
	int	error_read;
	int	error_mlx;
	int	error_config;
	int	error;
}				t_errors;
/*
**	Struct for map
*/
typedef	struct s_list_map
{
	char	*data;
	void	*next;
}	t_list_map;


typedef struct s_scene
{
	int		y;
	int		x;
	char	**map;
	int		map_size_x;
	int		map_size_y;
}	t_scene;

/*
** Struct for mlx
*/
typedef	struct s_mlx_data
{
	void	*mlx;
	void	*window;
}	t_mlx_data;

/*
** Struct for img
*/
typedef	struct s_img
{
	void			*id;
	unsigned int	*data;
	int				bpp;
	int				line_size;
	int				endian;
}	t_img;
/*
**	For all structs
*/

typedef struct s_tile
{
	char			type;
	unsigned int	color;
	int				sx;
	int				sy;
	int				x;
	int				y;
	t_img			img;
}					t_tile;

typedef struct s_all
{
	int				won;
	int				collect_count;
	t_tile			**tiles;
	t_tile			player;
	t_img			empty_img;
	t_img			wall_img;
	t_img			player_img;
	t_img			exit_img;
	t_img			collect_img;
	t_mlx_data	mlx;
	t_errors	errors;
	t_scene		scene;
	t_img		img;
}	t_all;

void	errors(int id, t_all *all);
void	game_over(t_all *all);

void	create_map(char *file, t_all *all);

void	more_init(t_all *all);

void	window_create(t_all *all);

int		hooks(int key, void *arg);

#endif