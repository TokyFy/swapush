/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:53:19 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/14 11:41:58 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ft_stack_rotate(t_stack *stack)
{
	t_list	*top;

	top = ft_stack_pop(stack);
	ft_lstadd_back(&stack->head, top);
  stack->size++;
}
