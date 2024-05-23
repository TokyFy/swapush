/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:20:56 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/22 21:51:59 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_all_digit(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

char ** parse_input(int argc , char *argv[])
{
    char *str = ft_strdup("");
    for (int i = argc - 1; i > 0; i--)
    {
        if(!ft_is_all_digit(argv[i]))
        {
            return (NULL);
        }
        char *temp = ft_strjoin(str, " "); // Add a space before the number
        char *temp2 = ft_strjoin(temp, argv[i]);
        free(temp);
        free(str);
        str = temp2;
    }
    return (ft_split(str, ' '));
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_b;
	t_stack	*stack_a;
	char    **input;ls

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	stack_b = ft_stack_new();
	stack_a = ft_stack_new();
	input = parse_input(argc, argv);

    while (*input)
    {
        ft_stack_push(stack_a, ft_itov(ft_atoi(*input)));
        input++;
    }

    ft_stack_print(stack_a);

	ft_sort_stack(stack_a, stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
