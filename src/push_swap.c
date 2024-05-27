/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:20:56 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/27 11:02:29 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

char	**parse_input(int argc, char *argv[])
{
	char	*str;
	char	*temp;
	char	*temp2;
	char	**splited;
	int		i;

	str = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if (!ft_is_all_digit(argv[i]))
			return (free(str), NULL);
		temp = ft_strjoin(str, " ");
		temp2 = ft_strjoin(temp, argv[i]);
		free(temp);
		free(str);
		str = temp2;
		i++;
	}
	splited = ft_split(str, ' ');
	free(str);
	if (have_duplicate(splited))
		return (free_splited(splited), NULL);
	return (splited);
}

void	process_input(t_stack *stack_a, char **input, int *error)
{
	long	n;

	while (!(*error) && *input)
	{
		n = ft_atol(*input);
		if (n > INT_MAX || n < INT_MIN)
		{
			*error = 1;
			break ;
		}
		ft_stack_push(stack_a, ft_itov(ft_atoi(*input)));
		ft_stack_rotate(stack_a);
		input++;
	}
}

void	handle_error_and_sort(t_stack *stack_a, t_stack *stack_b, int error)
{
	if (!error)
	{
		ft_sort_stack(stack_a, stack_b);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;
	int		error;

	stack_a = ft_stack_new();
	stack_b = ft_stack_new();
	input = parse_input(argc, argv);
	error = 0;
	if (!input)
	{
		error = 1;
	}
	else
	{
		process_input(stack_a, input, &error);
		free_splited(input);
	}
	handle_error_and_sort(stack_a, stack_b, error);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (error);
}
