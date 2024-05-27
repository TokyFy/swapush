/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:13:20 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/27 10:26:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sort_three(t_stack *a)
{
	t_list	*max;

	if (a->size <= 1 || a->size > 3)
		return ;
	max = ft_stack_max(a);
	if (max == a->head)
		ra(a);
	else if (a->size > 2 && (max == a->head->next))
		rra(a);
	if (!a->head->next || !a->head->next->next)
		return ;
	if ((*(int *)(a->head->content) > *(int *)(a->head->next->content)))
		sa(a);
}
