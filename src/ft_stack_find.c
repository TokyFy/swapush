/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:14:33 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/20 18:15:56 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max_index(t_stack *stack) {
    if (!stack->head)
        return 0;
    t_list *node = stack->head;
    int max_num = *(int *) (node->content);
    int max_index = 0;
    int index = 0;

    while (node) {
        if (*(int *) (node->content) > max_num) {
            max_num = *(int *) (node->content);
            max_index = index;
        }
        node = node->next;
        index++;
    }
    return max_index;
}

int find_min_index(t_stack *stack) {
    if (!stack->head)
        return 0;

    t_list *node = stack->head;
    int min_num = *(int *) (node->content);
    int min_index = 0;
    int index = 0;

    while (node) {
        if (*(int *) (node->content) < min_num) {
            min_num = *(int *) (node->content);
            min_index = index;
        }
        node = node->next;
        index++;
    }

    return min_index;
}

int ft_find_small_nearest(t_stack *stack, int n) {
    t_list *node = stack->head;
    int diff = INT_MAX;
    int temp = 0;
    int nearest = 0;
    int index = 0;

    while (node) {
        temp = n - *(int *) (node->content);
        if (temp > 0 && temp < diff) {
            diff = temp;
            nearest = index;
        }
        index++;
        node = node->next;
    }
    if (diff == INT_MAX)
        return find_max_index(stack);
    return nearest;
}

int ft_find_big_nearest(t_stack *stack, int n) {
    t_list *node = stack->head;
    int diff = INT_MAX;
    int temp = 0;
    int nearest = 0;
    int index = 0;

    while (node) {
        temp = *(int *) (node->content) - n;
        if (temp > 0 && temp < diff) {
            diff = temp;
            nearest = index;
        }
        index++;
        node = node->next;
    }
    if (diff == INT_MAX)
        return find_min_index(stack);
    return nearest;
}