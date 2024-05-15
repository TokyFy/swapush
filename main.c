/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/15 20:35:49 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libstack/libstack.h"
#include <stdio.h>
#include <stdlib.h>

void *ft_itov(int n) {
    int *p;

    p = malloc(sizeof(int));
    *p = n;
    return (p);
}

t_list *ft_stack_max(t_stack *stack) {
    t_list *max;
    t_list *i;

    max = stack->head;
    i = stack->head;
    while (i) {
        if (*(int *) (max->content) < *(int *) (i->content))
            max = i;
        i = i->next;
    }
    return (max);
}

int find_max_index(t_stack *stack) {
    t_list *node = stack->head;
    int max_num = *(int *)(node->content);
    int max_index = 0;
    int index = 0;

    while (node) {
        if (*(int *)(node->content) > max_num) {
            max_num = *(int *)(node->content);
            max_index = index;
        }
        node = node->next;
        index++;
    }
    return max_index;
}
int find_nearest_smaller_index(t_stack *stack, int n) {
    t_list *node = stack->head;
    int nearest = *(int *)(node->content);
    int diff;
    int nearest_index = 0;
    int index = 0;

    while (node) {
        diff = abs(n - *(int *)(node->content));
        if (diff < abs(n - nearest) && *(int *)(node->content) < n) {
            nearest = *(int *)(node->content);
            nearest_index = index;
        }
        node = node->next;
        index++;
    }
    return nearest_index;
}
int ft_find_small_nearest(t_stack *stack, int n) {
    int nearest_index = find_nearest_smaller_index(stack, n);
    int max_index = find_max_index(stack);

    if (*(int *)(stack->head->content) < n) {
        return nearest_index;
    } else {
        return max_index;
    }
}

void ft_stack_sort_three(t_stack *stack_a) {
    t_list *max;

    if (stack_a->size <= 1 || stack_a->size > 3)
        return;
    max = ft_stack_max(stack_a);
    if (max == stack_a->head)
        ra(stack_a);
    else if (stack_a->size > 2 && (max == stack_a->head->next))
        rra(stack_a);
    if ((*(int *) (stack_a->head->content) > *(int *) (stack_a->head->next->content)))
        sa(stack_a);
}

void ft_stack_sort(t_stack *stack_a, t_stack *stack) {

}

int main(void) {
    t_stack *stack_b;
    t_stack *stack_a;

    stack_b = ft_stack_new();
    stack_a = ft_stack_new();

    ft_stack_push(stack_a, ft_itov(5));
    ft_stack_push(stack_a, ft_itov(4));
    ft_stack_push(stack_a, ft_itov(2));
    ft_stack_push(stack_a, ft_itov(0));
    ft_stack_push(stack_a, ft_itov(1));

    ft_stack_print(stack_a);

    int n = 9;
    printf("The nearest integer to %d is %d\n", n, ft_find_small_nearest(stack_a, n));

    ft_stack_clear(&stack_a);
    ft_stack_clear(&stack_b);

    return 0;
}
