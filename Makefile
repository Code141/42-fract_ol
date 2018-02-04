# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 12:32:21 by gelambin          #+#    #+#              #
#    Updated: 2018/02/04 16:32:43 by gelambin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc

CFLAGS		=	#-Wall -Wextra -Werror

CPPFLAGS	=	-I./lib/mlx/					\
				-I./lib/libft/includes/			\
				-I./lib/mlxyz/includes/			\
				-I./includes/

LIBS		=	-L./lib/mlx -lmlx				\
				-L./lib/mlxyz -lmlxyz			\
				-L./lib/libft -lft

SRCS		=	./srcs/main.c					\
				./srcs/closing.c				\
				./srcs/loop.c

OBJS		=	$(SRCS:.c=.o)

FMWS		=	-framework OpenGL				\
				-framework AppKit

all			:	 $(NAME)

$(NAME) 	:	 $(OBJS)
	$(MAKE) -C ./lib/libft
	$(MAKE) -C ./lib/mlx 
	$(MAKE) -C ./lib/mlxyz 
	gcc -O3 $(LIBS) $(FMWS) $(OBJS) -o $(NAME)

clean		:
	rm -f $(OBJS)

fclean		:
	rm -f $(NAME) $(OBJS)

re			:
	$(MAKE) $(MFLAGS) fclean
	$(MAKE) $(MFLAGS) all

.PHONY		:	 all clean fclean re
