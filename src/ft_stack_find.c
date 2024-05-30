/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:14:33 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/30 09:33:27 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	t_list	*node;
	int		max_num;
	int		max_index;
	int		index;

	if (!stack->head)
		return (0);
	node = stack->head;
	max_num = *(int *)(node->content);
	max_index = 0;
	index = 0;
	while (node)
	{
		if (*(int *)(node->content) > max_num)
		{
			max_num = *(int *)(node->content);
			max_index = index;
		}
		node = node->next;
		index++;
	}
	return (max_index);
}

int	find_min_index(t_stack *stack)
{
	t_list	*node;
	int		min_num;
	int		min_index;
	int		index;

	if (!stack->head)
		return (0);
	node = stack->head;
	min_num = *(int *)(node->content);
	min_index = 0;
	index = 0;
	while (node)
	{
		if (*(int *)(node->content) < min_num)
		{
			min_num = *(int *)(node->content);
			min_index = index;
		}
		node = node->next;
		index++;
	}
	return (min_index);
}

int	ft_find_small_nearest(t_stack *stack, int n)
{
	t_list	*node;
	int		diff;
	int		temp;
	int		nearest;
	int		index;

	node = stack->head;
	diff = INT_MAX;
	temp = 0;
	nearest = 0;
	index = 0;
	while (node)
	{
		temp = n - *(int *)(node->content);
		if (temp > 0 && temp < diff)
		{
			diff = temp;
			nearest = index;
		}
		index++;
		node = node->next;
	}
	if (diff == INT_MAX)
		return (find_max_index(stack));
	return (nearest);
}

int	ft_find_big_nearest(t_stack *stack, int n)
{
	t_list	*node;
	int		diff;
	int		temp;
	int		nearest;
	int		index;

	node = stack->head;
	diff = INT_MAX;
	temp = 0;
	nearest = 0;
	index = 0;
	while (node)
	{
		temp = *(int *)(node->content) - n;
		if (temp > 0 && temp < diff)
		{
			diff = temp;
			nearest = index;
		}
		index++;
		node = node->next;
	}
	if (diff == INT_MAX)
		return (find_min_index(stack));
	return (nearest);
}
