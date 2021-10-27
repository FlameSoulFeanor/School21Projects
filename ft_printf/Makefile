# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 18:25:53 by hfunctio          #+#    #+#              #
#    Updated: 2021/01/26 15:50:39 by hfunctio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_flags.c\
		ft_processing_hex.c\
		ft_processing_int.c\
		ft_processing_per_char.c\
		ft_processing_point.c\
		ft_processing_str.c\
		ft_processing_unsgnd.c\
		ft_processing_width.c\
		ft_processing.c\
		
		
OBJS = ft_printf.o\
		ft_flags.o\
		ft_processing_hex.o\
		ft_processing_int.o\
		ft_processing_per_char.o\
		ft_processing_point.o\
		ft_processing_str.o\
		ft_processing_unsgnd.o\
		ft_processing_width.o\
		ft_processing.o\

HEADR = ft_printf.h

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

LIBFT=libft/libft.a

all:	$(NAME)

$(NAME):	$(OBJS) | $(LIBFT)
	ar rcs	$(NAME) $(OBJS)

$(OBJS): $(SRCS) $(HEADR)
	$(CC) $(FLAGS) -c $(SRCS)

$(LIBFT):
	make -C libft
	cp $(LIBFT) $(NAME)

clean:
	$(RM) $(OBJS)
	make -C libft clean 

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	make -C libft clean

re:		fclean all

.PHONY: all, clean, fclean, re
