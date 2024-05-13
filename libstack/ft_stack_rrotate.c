/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:54:27 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:38:37 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ft_stack_rotate_reverse(t_stack *stack)
{
	t_list	*temp;
	t_list	*last;

	temp = stack->head;
	while (temp->next && temp->next->next)
	{
		temp = temp->next;
	}
	last = temp->next;
	temp->next = NULL;
	ft_lstadd_front(&stack->head, last);
}
