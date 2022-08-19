# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 15:39:40 by gjupy             #+#    #+#              #
#    Updated: 2022/08/12 21:12:06 by gjupy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = pipex
CC    = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT = ./libs/libft/libft.a
SRCS  = ./srcs/main.c \
		./srcs/error/error.c ./srcs/error/error_2.c ./srcs/error/error_utils.c ./srcs/error/error_malloc.c\
		./srcs/utils/utils.c ./srcs/utils/utils_2.c\
		./srcs/free.c \
		./srcs/pipes.c \
		./srcs/childs.c \
		./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libs/libft
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

inside: $(OBJS) $(LIBFT)
	ar -t $(NAME)

git:
	git add .
	git commit -m "commit"
	git push

.PHONY: all clean fclean re git libft