/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:19:37 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/23 11:51:09 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pre_sort_stack(t_stack *a, t_stack *b)
{
	int	index_a;
	int	index_b;

	index_a = 0;
	index_b = 0;
	if (a->size > 3 && !b->head)
	{
		pb(a, b);
		pb(a, b);
	}

  if (a->size <= 3)
		return ;

	find_smallest_cost_move(a, b, &index_a, &index_b);
	execute_low_cost_move(a, b, index_a, index_b);
	pb(a, b);
	ft_pre_sort_stack(a, b);
}

int ft_is_sorted(t_stack *a)
{
  t_list *list = a->head;

  while (list && list->next) {
    if(*(int *)(list->content) > *(int *)(list->next->content))
      return 0;

    list = list->next;
  }
  return 1;
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	int		temp;
	t_list	*node;

  if(ft_is_sorted(a))
    return;

	temp = 0;
	ft_pre_sort_stack(a, b);
	if (a->size <= 3)
		ft_stack_sort_three(a);
	node = b->head;
	while (node)
	{
		node = b->head;
		if (!node)
			break ;
		temp = ft_find_big_nearest(a, *(int *)(node->content));
		if (temp < a->size / 2)
		{
			while (temp-- > 0)
				ra(a);
		}
		else
		{
			temp = a->size - temp;
			while (temp-- > 0)
				rra(a);
		}
		pa(a, b);
	}
	temp = find_min_index(a);
	if (temp < a->size / 2)
	{
		while (temp-- > 0)
			ra(a);
	}
	else
	{
		temp = a->size - temp;
		while (temp-- > 0)
			rra(a);
	}
}
