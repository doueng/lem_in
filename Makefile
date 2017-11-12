# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: douglas <douglas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 09:25:40 by dengstra          #+#    #+#              #
#    Updated: 2017/11/12 17:16:31 by dengstra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wextra -Wall -Werror
LIBFT = ./libft
LIB = libft/libft.a

SRC = main.c error.c creator.c parser.c priority_queue.c shortest_path.c	\
		printer.c check_input.c checker.c

SRCO = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME): $(SRCO)
	make -C $(LIBFT)
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	/bin/rm -f $(SRCO)
	make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean re all
