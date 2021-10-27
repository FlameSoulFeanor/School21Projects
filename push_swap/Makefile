# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 11:48:53 by hfunctio          #+#    #+#              #
#    Updated: 2021/08/03 14:55:11 by hfunctio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS =  srcs/errors.c \
		srcs/push_swap.c \
		srcs/sort.c \
		srcs/three_five_sort.c \
		srcs/ss.c \
		srcs/rrr.c \
		srcs/pb_pa.c \
		srcs/main_sort.c \
		srcs/start_sort.c 

OBJSDIR = Temporary

OBJS = $(subst srcs/,$(OBJSDIR)/,$(SRCS:.c=.o))

HDR = -I./includes

LIBFT_HDR = -I./includes/libft

LIBFT_BIN = -L./includes/libft -lft

LIBFT = ./includes/libft/libft.a

all: $(LIBFT) ./includes/libft/libft.a $(NAME)

FORCE:		;

LIBFT = ./includes/libft/libft.a

$(LIBFT):	FORCE
			make -C ./includes/libft

$(OBJSDIR):
	mkdir $@

$(OBJSDIR)/%.o: srcs/%.c | $(OBJSDIR)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJS) $(LIBFT_BIN) -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSDIR)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./includes/libft fclean

re: fclean all
