# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 12:32:21 by gelambin          #+#    #+#              #
#    Updated: 2018/03/21 14:25:46 by gelambin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I./mlx/							\
				-I./libft/includes/					\
				-I./mlxyz/includes/					\
				-I./includes/						\

LIBS		=	-L./mlx -lmlx						\
				-L./mlxyz -lmlxyz					\
				-L./libft -lft

SRCS		=	./srcs/main.c						\
				./srcs/params.c						\
				./srcs/devices_events.c				\
				./srcs/cl.c							\
				./srcs/move.c						\
				./srcs/closing.c					\
				./srcs/txt.c						\
				./srcs/loop.c						\
				./srcs/common.c						\
				./srcs/fractals/julia.c				\
				./srcs/fractals/mandelbrot.c		\
				./srcs/fractals/burning_ship.c		\
				./srcs/fractals/tricorn.c			\
				./srcs/fractals/bullet.c			\
				./srcs/fractals/julia_fun.c			\
				./srcs/fractals/sierpinski_carpet.c	\
				./srcs/fractals/zappa.c

OBJS		=	$(SRCS:.c=.o)

FMWS		=	-framework OpenGL					\
				-framework OpenCL					\
				-framework AppKit

# **************************************************************************** #

all			:	 $(NAME)

$(NAME) 	:	libs $(OBJS)
	$(CC) -O3 $(LIBS) $(FMWS) $(OBJS) -o $(NAME)

clean		:	libsclean
	rm -f $(OBJS)

fclean		:	libsfclean clean
	rm -f $(NAME)

re			:
	$(MAKE) $(MFLAGS) fclean
	$(MAKE) $(MFLAGS) all

.PHONY		:	 all libs libsclean libsfclean clean fclean re

# **************************************************************************** #

libs		:
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx 
	$(MAKE) -C ./mlxyz 

libsclean	:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx 
	$(MAKE) clean -C ./mlxyz 

libsfclean	:
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./mlx 
	$(MAKE) fclean -C ./mlxyz 

# **************************************************************************** #

g			:	libs $(OBJS)
	$(CC) -O3 -g $(LIBS) $(FMWS) $(OBJS) -o $(NAME)

fsanitize	:	libs $(OBJS)
	$(CC) -O3 -g -fsanitize=address $(LIBS) $(FMWS) $(OBJS) -o $(NAME)

norminette	:
	norminette $(SRCS) ./includes ./libft/ ./mlxyz
