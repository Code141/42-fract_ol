# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 12:32:21 by gelambin          #+#    #+#              #
#    Updated: 2018/03/19 20:13:40 by gelambin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I./lib/mlx/						\
				-I./lib/libft/includes/				\
				-I./lib/mlxyz/includes/				\
				-I./includes/						\

LIBS		=	-L./lib/mlx -lmlx					\
				-L./lib/mlxyz -lmlxyz				\
				-L./lib/libft -lft

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

all			:	 $(NAME)

libs		:
	@echo 'Compiling libft'
	@$(MAKE) -C ./lib/libft
	@echo 'Compiling mlx'
	@$(MAKE) -C ./lib/mlx 
	@echo 'Compiling mlxyz'
	@$(MAKE) -C ./lib/mlxyz 

$(NAME) 	:	libs $(OBJS)
	@echo 'Compiling '$(NAME)
	@$(CC) -O3 $(LIBS) $(FMWS) $(OBJS) -o $(NAME)

clean		:
	@echo 'Remove .objects files'
	@rm -f $(OBJS)

fclean		:	clean
	@echo 'Remove app'
	@rm -f $(NAME)

re			:
	@$(MAKE) $(MFLAGS) fclean
	@$(MAKE) $(MFLAGS) all

.PHONY		:	 all clean fclean re

################################################################################

g: $(OBJS)
	$(CC) -O3 -g $(LIBS) $(FMWS) $(OBJS) -o $(NAME)

fsanitize: $(OBJS)
	$(CC) -O3 -g -fsanitize=address $(LIBS) $(FMWS) $(OBJS) -o $(NAME)
