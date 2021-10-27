NAME 		= cub3D

SRCS_DIR	= ./srcs/main.c \
			  ./srcs/floor_ceil_create.c \
			  ./srcs/inits.c \
			  ./srcs/game_over.c \
			  ./srcs/path_create.c \
			  ./srcs/resolution_create.c \
			  ./srcs/color_create.c \
			  ./srcs/create_scene.c \
			  ./srcs/map_create.c \
			  ./srcs/map_create_2.c \
			  ./srcs/map_check.c \
			  ./srcs/check_spaces.c \
			  ./srcs/check_sides.c \
			  ./srcs/vectors_init.c \
			  ./srcs/sprites_init.c \
			  ./srcs/texture_init.c \
			  ./srcs/press_key.c \
			  ./srcs/move_player.c \
			  ./srcs/creat_raycasting.c \
			  ./srcs/draw_sprites.c \
			  ./srcs/init_sprites.c \
			  ./srcs/free_list_map.c \
			  ./srcs/cast_all.c \
			  ./get_next_line/get_next_line.c \
			  ./get_next_line/get_next_line_utils.c \
			  ./srcs/create_bmp.c \
			  ./srcs/errors.c \

HEAD_DIR 	= ./includes/

OBJS 		= $(SRCS_DIR:.c=.o)

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g

MINILIBX  	= libmlx.a
MINILIBX_FLAGS = -framework OpenGL -framework AppKit

L_MINILIBX 	= ./minilibx_opengl/libmlx.a
L_LIBFT		= ./libft/libft.a

.c.o:
	${CC} ${CFLAGS} -I ${HEAD_DIR} -c $< -o $@

$(NAME): ${OBJS}
			make -C ./minilibx_opengl
			make -C ./libft
			${CC} ${CFLAGS} ${MINILIBX_FLAGS} -I ${HEAD_DIR} ${L_MINILIBX} ${L_LIBFT} ${OBJS} -o ${NAME} 

bonus: $(OBJS)

all: ${NAME}

clean:
			$(MAKE) -C ./minilibx_opengl clean
			$(MAKE) -C ./libft fclean
			rm -f $(OBJS)

fclean: clean
			rm -f $(MINILIBX)
			rm -f ${NAME}

re:			fclean all


