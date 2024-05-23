/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:20:56 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/23 12:45:36 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int ft_is_all_digit(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

char** parse_input(int argc , char *argv[])
{
    char *str = ft_strdup("");
    for (int i = 1 ; i < argc; i++)
    {
        if(!ft_is_all_digit(argv[i]))
        {
            return (NULL);
        }
        char *temp = ft_strjoin(str , " ");
        char *temp2 = ft_strjoin(temp , argv[i]);
        free(temp);
        free(str);
        str = temp2;
    }

    return ft_split(str, ' ');
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_b;
	t_stack	*stack_a;
	char    **input;

	stack_b = ft_stack_new();
	stack_a = ft_stack_new();

  (void)(stack_b);
  (void)(stack_a);

	input = parse_input(argc, argv);
  
  (void)(input);
  if(!input)
  {
    ft_putendl_fd("Error" , 2);
    return 1;
  }

  while (*input)
  {
        ft_stack_push(stack_a, ft_itov(ft_atoi(*input)));
        ft_stack_rotate(stack_a);
        input++;
  }

  //
  ft_stack_print(stack_a);
  // ft_stack_print(stack_b);

	ft_sort_stack(stack_a, stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
