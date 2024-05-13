/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:21:51 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:42:18 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	s(t_stack *a)
{
	t_list	*head;
	t_list	*head_next;

	if (ft_stack_is_empty(a))
		return ;
	head = ft_stack_pop(a);
	head_next = ft_stack_pop(a);
	ft_stack_push(a, head->content);
	ft_stack_push(a, head_next->content);
	ft_lstdelone(head, nothing);
	ft_lstdelone(head_next, nothing);
}

void	sa(t_stack *a)
{
	s(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b)
{
	s(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	s(a);
	s(b);
	ft_putendl_fd("ss", 1);
}
