/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:51:05 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 11:51:08 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

t_list	*ft_stack_pop(t_stack *stack)
{
	t_list	*poped;

	if (!stack->head)
		return (NULL);
	stack->size--;
	poped = stack->head;
	stack->head = stack->head->next;
	poped->next = NULL;
	return (poped);
}