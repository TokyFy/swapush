/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:20:56 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/25 14:18:57 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int ft_is_all_digit(char *str)
{
    int i = 0;

    if(str[i] == '+' || str[i] == '-')
      i++;

    if(!str[i])
      return 0;

    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

void free_splited(char **str)
{
  if(!str)
    return;
  char **temp = str;

  while (*temp) {
    free(*temp);
    temp++;
  }

  free(str);
}

int have_duplicate(char **str)
{
  int i = 0;
  int j = 0;

  while (str[i]) {
    j = i + 1;
    while (str[j]) {
      if(ft_strncmp(str[i], str[j], -1) == 0)
        return 1;
      j++;
    }
    i++;
  }

  return 0;
}

char** parse_input(int argc , char *argv[])
{
    char *str = ft_strdup("");
    for (int i = 1 ; i < argc; i++)
    {
        if(!ft_is_all_digit(argv[i]))
        {
            free(str);
            return (NULL);
        }
        char *temp = ft_strjoin(str , " ");
        char *temp2 = ft_strjoin(temp , argv[i]);
        free(temp);
        free(str);
        str = temp2;
    }
    
    char ** splited = ft_split(str, ' ');
    free(str);

    if(have_duplicate(splited))
    {
      free_splited(splited);
      return NULL;
    }

    return splited;
}


int	main(int argc, char *argv[])
{
	t_stack	*stack_b;
	t_stack	*stack_a;
	char    **input;
  int error = 0;

	stack_b = ft_stack_new();
	stack_a = ft_stack_new();

  (void)(stack_b);
  (void)(stack_a);

	input = parse_input(argc, argv);

  if(!input)
    error = 1 ;

  char **ss = input;
  while (!error && *input)
  {
        long n = ft_atol(*input);
        
        if(n > INT_MAX || n < INT_MIN)
        {
          printf("OVERFLOWWWW");
          error = 1;
          break;
        }

        ft_stack_push(stack_a, ft_itov(ft_atoi(*input)));
        ft_stack_rotate(stack_a);
        input++;
  }

  free_splited(ss);
  if(!error)
	  ft_sort_stack(stack_a, stack_b);
  else
   ft_putstr_fd("Error\n", 2);

  ft_stack_print(stack_a);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
  return (error);
}
