# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 17:24:51 by aralves-          #+#    #+#              #
#    Updated: 2024/03/20 17:40:26 by aralves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =		free.c		\
			ft_allocatebsq.c	\
			ft_atoi.c		\
			ft_bsq.c		\
			ft_endbsq.c		\
			ft_mapvalidation.c	\
			ft_strlen.c		\
			solve_square.c	\
			main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME);

re: fclean all

.PHONY: re clean fclean all