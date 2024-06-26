# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franaivo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:07:39 by franaivo          #+#    #+#              #
#    Updated: 2024/05/27 10:57:17 by franaivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = src/ft_stack_find.c src/ft_stack_max.c src/ft_stack_move.c \
			src/ft_stack_sort.c src/ft_stack_sort_three.c  src/push_swap.c \
			src/ft_stack_cost.c src/ft_nbr_utils.c src/ft_str_utils.c

CC = gcc
FLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
LIBFT = libft/libft.a
LIBSTACK = libstack/libstack.a

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(LIBSTACK)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBSTACK) $(LIBFT) -o $(NAME)

$(OBJECTS) : %.o : %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT) :
	$(MAKE) bonus -C ./libft/

$(LIBSTACK) :
	$(MAKE) -C ./libstack/

clean:
	$(MAKE) fclean -C ./libstack/
	$(MAKE) fclean -C ./libft/
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

lib : all clean

re : fclean all

