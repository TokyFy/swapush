/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:13:20 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/22 14:33:10 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sort_three(t_stack *stack_a)
{
	t_list	*max;

	if (stack_a->size <= 1 || stack_a->size > 3)
		return ;
	max = ft_stack_max(stack_a);
	if (max == stack_a->head)
		ra(stack_a);
	else if (stack_a->size > 2 && (max == stack_a->head->next))
		rra(stack_a);
	if ((*(int *)(stack_a->head->content) > *(int *)(stack_a->head->next->content)))
		sa(stack_a);
}
