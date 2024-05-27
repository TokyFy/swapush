/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:56:01 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/23 11:42:57 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ft_stack_rotate(t_stack *stack)
{
	t_list	*top;

	if (ft_stack_is_empty(stack) || stack->size <= 1)
	{
		return ;
	}
	top = ft_stack_pop(stack);
	ft_lstadd_back(&stack->head, top);
	stack->size++;
}
