# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 21:09:18 by gelambin          #+#    #+#              #
#    Updated: 2018/01/31 18:38:26 by gelambin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CLIB	= -I./includes/
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+=-O3

SRCS = 	ft_atoi.c		ft_bzero.c		ft_isalnum.c	ft_isalpha.c		\
		ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_itoa.c			\
		ft_memalloc.c	ft_memccpy.c	ft_memchr.c		ft_memcmp.c			\
		ft_memcpy.c		ft_memdel.c		ft_memmove.c	ft_memset.c			\
		ft_putchar.c	ft_putchar_fd.c	ft_putendl.c	ft_putendl_fd.c		\
		ft_putnbr.c		ft_putnbr_fd.c	ft_putstr.c		ft_putstr_fd.c		\
		ft_strcat.c		ft_strchr.c		ft_strclr.c		ft_strcmp.c			\
		ft_strcpy.c		ft_strdel.c		ft_strdup.c		ft_strequ.c			\
		ft_striter.c	ft_striteri.c	ft_strjoin.c	ft_strlcat.c		\
		ft_strlen.c		ft_strmap.c		ft_strmapi.c	ft_strncat.c		\
		ft_strncmp.c	ft_strncpy.c	ft_strnequ.c	ft_strnew.c			\
		ft_strnstr.c	ft_strrchr.c	ft_strsplit.c	ft_strstr.c			\
		ft_strsub.c		ft_strtrim.c	ft_tolower.c	ft_toupper.c

SRCS +=	ft_lstnew.c			ft_lstdelone.c			ft_lstdel.c				\
		ft_lstiter.c		ft_lstmap.c				ft_lst_push_front.c		\
		ft_lst_push_back.c	ft_lst_weight.c			ft_lst_fold.c			\
		ft_lst_remove.c		ft_lst_new_link.c

SRCS +=	ft_atoi_base.c	ft_sqrt.c		ft_factorial.c	ft_power.c			\
		ft_putnbr_base.c

SRCS +=	ft_get_next_line.c

INC =	libft.h

OBJS = $(SRCS:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) $(CLIB) -c $?

all : $(NAME) 

$(NAME) : $(OBJS)
	ar rc $(NAME) $?
	ranlib $(NAME)

clean :
	/bin/rm -f $(OBJS)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean clean re
