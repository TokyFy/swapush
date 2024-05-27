/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:17:02 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/27 10:13:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parallel_rr(t_stack *stack_a, t_stack *stack_b, int index, int b_index)
{
	index = stack_a->size - index;
	b_index = stack_b->size - b_index;
	while (index > 0 && b_index > 0)
	{
		rrr(stack_a, stack_b);
		index--;
		b_index--;
	}
	while (index-- > 0)
		rra(stack_a);
	while (b_index-- > 0)
		rrb(stack_b);
}

void	parallel_r(t_stack *stack_a, t_stack *stack_b, int index, int b_index)
{
	while (index > 0 && b_index > 0)
	{
		rr(stack_a, stack_b);
		index--;
		b_index--;
	}
	while (index-- > 0)
		ra(stack_a);
	while (b_index-- > 0)
		rb(stack_b);
}

void	cross_rr(t_stack *stack_a, t_stack *stack_b, int index, int b_index)
{
	if (index < stack_a->size / 2)
	{
		while (index-- > 0)
			ra(stack_a);
	}
	else
	{
		index = stack_a->size - index;
		while (index-- > 0)
			rra(stack_a);
	}
	if (b_index < stack_b->size / 2)
	{
		while (b_index-- > 0)
			rb(stack_b);
	}
	else
	{
		b_index = stack_b->size - b_index;
		while (b_index-- > 0)
			rrb(stack_b);
	}
}

void	execute_low_cost_move(t_stack *stack_a, t_stack *stack_b, int index,
		int b_index)
{
	if (index > stack_a->size / 2 && b_index > stack_b->size / 2)
	{
		return (parallel_rr(stack_a, stack_b, index, b_index));
	}
	if (index < stack_a->size / 2 && b_index < stack_b->size / 2)
	{
		return (parallel_r(stack_a, stack_b, index, b_index));
	}
	return (cross_rr(stack_a, stack_b, index, b_index));
}
