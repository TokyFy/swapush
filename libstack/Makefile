# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franaivo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:07:39 by franaivo          #+#    #+#              #
#    Updated: 2024/05/13 12:17:08 by franaivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = ft_stack_new.c ft_print_stack.c ft_clear_stack.c ft_rotate_reverse_stack.c \
					ft_rotate_stack.c ft_stack_pop.c ft_stack_push.c ft_utils_stack.c is_stack_empty.c  

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libstack.a

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : %.o : %.c
	@$(CC) -c $(FLAGS) $< -o $@


clean:
	@rm -f $(OBJECTS) 

fclean: clean
	@rm -rf $(NAME)

lib : all clean

re : fclean all

