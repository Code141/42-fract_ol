# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 12:32:21 by gelambin          #+#    #+#              #
#    Updated: 2018/03/08 19:31:25 by gelambin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libmlxyz.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS=	-I../mlx/						\
			-I../libft/includes/			\
			-I./includes/

LIBS	=	-L../mlx -lmlx					\
			-L../libft -lft

SRCS	=	./srcs/core/core.c				\
			./srcs/core/loop.c				\
			\
			./srcs/events/events.c			\
			./srcs/events/mouse.c			\
			./srcs/events/keyboard.c		\
			\
			./srcs/screen/screen.c			\
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
			./srcs/draw/square.c			\
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
			./srcs/object/mesh.c			\
			\
			./srcs/opencl/opencl.c

OBJS	=	$(SRCS:.c=.o)

FMWS	=	-framework OpenGL				\
			-framework AppKit

all		: $(NAME)

#libft.a:	./lib/libft/libft.a
#	$(MAKE) -C ./lib/libft 

$(NAME) : $(OBJS)
	$(MAKE) -C ../libft
	$(MAKE) -C ../mlx 
	ar rc $(NAME) $?

clean	:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re:
	$(MAKE) $(MFLAGS) fclean
	$(MAKE) $(MFLAGS) all

.PHONY: all clean fclean re
