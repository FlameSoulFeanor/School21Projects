/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:17:37 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/16 16:17:23 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx_opengl/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define PI 3.14159265
/*
** Define keys
*/
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_LA 123
# define KEY_RA 124
# define KEY_ESC 53
/*
** Define resolution size
*/
# define MIN_Y 100
# define MIN_X 100
# define MAX_Y 1440
# define MAX_X 2560
/*
** Map struct
*/
typedef struct s_list_map
{
	char	*data;
	void	*next;
}				t_list_map;
/*
** Resolution struct
*/
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_d_vector
{
	double	x;
	double	y;
	double	x_dir;
	double	y_dir;
	double	x_cam;
	double	y_cam;
}				t_d_vector;
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
	int	error_resolution;
	int	error_floor;
	int	error_ceil;
	int	error_texture;
	int	error;
}				t_errors;
/*
** For image struct
*/
typedef struct s_image
{
	void	*ptr;
	char	*data;
	char	*directory;
	int		bpp;
	int		line_size;
	int		endian;
}				t_image;
/*
** Scene create
*/
typedef struct s_scene
{
	t_vector	resol;
	t_vector	map_size;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*sprite_texture;
	int			floor_clr;
	int			ceil_clr;
	char		*map;
	int			save;
	t_image		north_path;
	t_image		south_path;
	t_image		west_path;
	t_image		east_path;
	t_image		sprite_path;
}				t_scene;
/*
** Struct for window create
*/
typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
}				t_mlx_data;
/*
** Casts
*/
typedef struct s_raytrace
{
	int			side;
	double		vector;		
	double		x_ray;
	double		y_ray;
	double		x_delta;
	double		y_delta;
	double		x_step;
	double		y_step;
	int			x_map;
	int			col_height;
	int			y_map;
	double		x_s;
	double		y_s;
	double		height_wall;
	t_image		*texture;
}				t_raytrace;
typedef struct s_cast
{
	double	*list_dist;
	int		curr;
}				t_cast;
/*
** Struct for sprite
*/
typedef struct s_sprite
{
	int	x;
	int	y;
}				t_sprite;

typedef struct s_list_sprite
{
	t_sprite	sprite;
	void		*next;
}				t_list_sprite;

typedef struct s_var_sprite
{
	double	mult_const;
	double	x_cast;
	double	y_cast;
	double	dist;
	int		middle;
	int		x_launch;
	int		y_launch;
	int		x_finish;
	int		y_finish;
}	t_var_sprite;
/*
** For all structs
*/
typedef struct s_all
{
	t_raytrace		ray;
	t_cast			list_dist;
	t_image			image;
	t_mlx_data		mlx;
	t_list_sprite	*sprites;
	t_d_vector		player;
	t_scene			scene;
	t_errors		errors;
}	t_all;

void	game_over(t_all *all);
void	ft_errors(int ind, t_all *all);

void	create_scene(char *file, t_all *all);

void	init_struct(t_all *all);

void	path_create(char *line, t_all *all);
void	free_split(char **str);
void	check_nbr_arg(char **str, int num, t_all *all);
int		check_num(char *str);
void	check_up_down_map(int i, char *map, t_all *all);
void	check_left_right_map(int i, char *map, t_all *all);
void	args_free(t_all *all);

void	resolution_create(char *line, t_all *all);
void	color_create(char *line, t_all *all);
void	map_create(char *line, int fd, t_all *all);

void	map_create_all(t_list_map *list, t_all *all);

void	free_list_map(t_list_map *list);

void	map_check(t_all *all);
void	cast_all(t_all *all);
int		check_spaces(int i, t_all *all);
void	check_spaces_in_str(int i, t_all *all);
void	check_map_in_empty(int i, char *map, t_all *all);

void	check_space_up(int i, int j, t_all *all);
void	check_space_down(int i, int j, t_all *all);
void	check_left_space(int i, int j, t_all *all);
void	check_right_space(int i, int j, t_all *all);

void	player_init(t_all *all);
void	vectors_init(char c, int i, int j, t_all *all);
void	sprites_init(t_all *all);
void	texture_init(t_all *all);

int		press_key(int key, t_all *all);
int		press_close(t_all *all);

void	move_player(int key, t_all *all);

void	floor_create(t_all *all);
void	ceil_create(t_all *all);

void	create_raycasting(int x, t_all *all);
void	ray_find(t_all *all);
void	step_create(t_all *all);
void	texture_find(t_all *all);
void	height_find(t_all *all);

void	draw_sprites(t_all *all);
void	list_parsing(t_sprite *list, int *range, int list_len, t_all *all);
void	sprite_calc(t_sprite *srite, t_var_sprite *var, t_all *all);
void	more_calc(t_var_sprite *var, t_all *all);
void	list_sort(t_sprite *list, int *range, int list_len);
void	create_bmp(t_all *all);

#endif
