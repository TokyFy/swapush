/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:20:56 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/20 19:22:59 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/20 18:29:49 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_b;
	t_stack	*stack_a;
	int		num;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	stack_b = ft_stack_new();
	stack_a = ft_stack_new();
	for (int i = argc - 1; i > 0; i--)
	{
		num = ft_atoi(argv[i]);
		ft_stack_push(stack_a, ft_itov(num));
	}
	ft_sort_stack(stack_a, stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
