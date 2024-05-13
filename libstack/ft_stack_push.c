/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:12 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 12:26:44 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ft_stack_push(t_stack *stack, void *content)
{
	t_list	*new_top;

	new_top = ft_lstnew(content);
	ft_lstadd_front(&stack->head, new_top);
	stack->size++;
}
