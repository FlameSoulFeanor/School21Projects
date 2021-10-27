NAME = so_long

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/get_next_line.c \
	   srcs/get_next_line_utils.c \
	   srcs/main.c \
	   srcs/errors.c \
	   srcs/create_map.c \
	   srcs/more_init.c	\
	   srcs/window_create.c	\
	   srcs/hooks.c	

OBJSDIR = tmp

OBJS = $(subst srcs/,$(OBJSDIR)/,$(SRCS:.c=.o))

HDR = -I./includes

LIBFT_HDR = -I./includes/libft

LIBFT_BIN = -L./includes/libft -lft

LIBFT = ./includes/libft/libft.a

all: $(LIBFT) ./includes/libft/libft.a $(NAME)

MINILIBX = libmlx.a
MINILIBX_FLAGS = -framework OpenGL -framework Appkit

L_MINILIBX = ./minilibx_opengl/libmlx.a


FORCE:		;

LIBFT = ./includes/libft/libft.a

$(LIBFT):	FORCE
			make -C ./includes/libft

$(OBJSDIR):
	mkdir $@

$(OBJSDIR)/%.o: srcs/%.c | $(OBJSDIR)
	gcc -g $(CFLAGS) $(HDR) $ $(LIBFT_HDR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) ./includes/so_long.h
	make -C ./minilibx_opengl
	gcc -g $(OBJS) $(LIBFT_BIN) ${MINILIBX_FLAGS} ${L_MINILIBX} -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSDIR)
	make -C ./includes/libft fclean
	make -C ./minilibx_opengl clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./includes/libft fclean
	rm -f $(MINILIBX)

re: fclean all
