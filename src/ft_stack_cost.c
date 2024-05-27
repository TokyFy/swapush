/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:12:46 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/27 10:13:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int index, int b_index)
{
	if (index < stack_a->size / 2 && b_index < stack_b->size / 2)
		return (max(index, b_index));
	if (index > stack_a->size / 2 && b_index > stack_b->size / 2)
		return (max(stack_a->size - index, stack_b->size - b_index));
	return (min(index + (stack_b->size - b_index), b_index + (stack_a->size
				- index)));
}

void	find_smallest_cost_move(t_stack *a, t_stack *b, int *a_index,
		int *b_index)
{
	t_list	*node;
	int		index;
	int		cost;
	int		temp;
	int		small;

	node = a->head;
	index = 0;
	cost = INT_MAX;
	temp = 0;
	small = 0;
	while (node)
	{
		small = ft_find_small_nearest(b, *(int *)node->content);
		temp = calculate_cost(a, b, index, small);
		if (temp < cost)
		{
			*a_index = index;
			*b_index = small;
			cost = temp;
		}
		index++;
		node = node->next;
	}
}
