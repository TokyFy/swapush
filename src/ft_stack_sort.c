/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:19:37 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/20 18:20:16 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pre_sort_stack(t_stack *a, t_stack *b) {
    int index_a = 0;
    int index_b = 0;

    if (a->size <= 3)
        return;

    if (!b->head) {
        pb(a, b);
        pb(a, b);
    }

    find_smallest_cost_move(a, b, &index_a, &index_b);
    execute_low_cost_move(a, b, index_a, index_b);
    pb(a, b);
    ft_pre_sort_stack(a, b);
}

void ft_sort_stack(t_stack *a, t_stack *b) {
    int temp = 0;
    ft_pre_sort_stack(a, b);

    if (a->size == 3)
        ft_stack_sort_three(a);

    t_list *node = b->head;

    while (node) {
        node = b->head;
        if (!node)
            break;
        temp = ft_find_big_nearest(a, *(int *) (node->content));

        if (temp < a->size / 2) {
            while (temp-- > 0)
                ra(a);
        } else {
            temp = a->size - temp;
            while (temp-- > 0)
                rra(a);
        }
        pa(a, b);
    }
    temp = find_min_index(a);

    if (temp < a->size / 2) {
        while (temp-- > 0)
            ra(a);
    } else {
        temp = a->size - temp;
        while (temp-- > 0)
            rra(a);
    }
}