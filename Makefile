# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franaivo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:07:39 by franaivo          #+#    #+#              #
#    Updated: 2024/05/13 15:34:27 by franaivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = ft_stack_clear.c ft_stack_is_empty.c ft_stack_new.c ft_stack_pop.c \
					ft_stack_print.c ft_stack_push.c ft_stack_rotate.c ft_stack_rrotate.c \
					ft_stack_utils.c ft_p.c ft_r.c ft_rr.c ft_s.c

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

