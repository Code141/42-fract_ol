# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 12:32:21 by gelambin          #+#    #+#              #
#    Updated: 2018/02/01 18:46:41 by gelambin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror
CPPFLAGS=	-I./lib/mlx/					\
			-I./lib/libft/includes/			\
			-I./includes/					\
			-I./includes/events/			\
			-I./includes/math/				\
			-I./includes/draw/				\
			-I./includes/hud/				\
			-I./includes/geometry/			\
			-I./includes/material/			\
			-I./includes/color/				\
			-I./includes/object/			\
			-I./includes/app/

LIBS	=	-L./lib/mlx -lmlx				\
			-L./lib/libft -lft

SRCS	=	./srcs/main.c					\
			./srcs/app/closing.c			\
			./srcs/app/events.c				\
			./srcs/app/screen.c				\
			./srcs/app/loop.c				\
			\
			./srcs/events/mouse.c			\
			./srcs/events/keyboard.c		\
			\
			./srcs/hud/hud.c				\
			./srcs/hud/stats.c				\
			./srcs/hud/graph.c				\
			\
			./srcs/math/pixel.c				\
			./srcs/math/vector.c			\
			./srcs/math/vector3.c			\
			./srcs/math/vector4.c			\
			./srcs/math/matrice4.c			\
			./srcs/math/matrice4_rot_trans.c\
			\
			./srcs/draw/draw.c				\
			./srcs/draw/draw_mesh.c			\
			./srcs/draw/draw_hud.c			\
			./srcs/draw/bresenham_line.c	\
			\
			./srcs/geometry/geometry.c		\
			./srcs/geometry/cube.c			\
			./srcs/geometry/plane.c			\
			./srcs/geometry/surface.c		\
			./srcs/geometry/surface2.c		\
			\
			./srcs/material/material.c		\
			\
			./srcs/color/rgba.c				\
			\
			./srcs/object/object.c			\
			./srcs/object/scene.c			\
			./srcs/object/camera.c			\
			./srcs/object/mesh.c

OBJS	=	$(SRCS:.c=.o)

FMWS	=	-framework OpenGL				\
			-framework AppKit

all		: $(NAME)

$(NAME) : $(OBJS)
	cd ./lib/libft && $(MAKE)
	cd ./lib/mlx && $(MAKE)
	gcc -O3 $(LIBS) $(FMWS) $(OBJS) -o $(NAME)

clean	:
	rm -f $(OBJS)
	cd ./lib/libft && $(MAKE) clean
	cd ./lib/mlx && $(MAKE) clean

fclean:
	rm -f $(NAME) $(OBJS)
	cd ./lib/libft && $(MAKE) fclean
	cd ./lib/mlx && $(MAKE) clean

re:
	$(MAKE) $(MFLAGS) fclean
	$(MAKE) $(MFLAGS) all

.PHONY: all clean fclean re
