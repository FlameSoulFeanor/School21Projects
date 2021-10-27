# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 10:53:16 by hfunctio          #+#    #+#              #
#    Updated: 2021/09/09 10:53:32 by hfunctio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS =  srcs/main.c \
		srcs/error.c \
		srcs/pipe.c

OBJSDIR = Temporary

OBJS = $(subst srcs/,$(OBJSDIR)/,$(SRCS:.c=.o))

HDR = -I./includes

LIBFT_HDR = -I./includes/libft

LIBFT_BIN = -L./includes/libft -lft

LIBFT = ./includes/libft/libft.a

all: $(LIBFT) ./includes/libft/libft.a $(NAME)

FORCE:		;

$(LIBFT):	FORCE
			make -C ./includes/libft

$(OBJSDIR):
	mkdir $@

$(OBJSDIR)/%.o: srcs/%.c | $(OBJSDIR)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) ./includes/pipex.h
	gcc -g  $(OBJS) $(LIBFT_BIN) -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSDIR)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./includes/libft fclean

re: fclean all