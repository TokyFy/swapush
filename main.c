/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/20 18:08:03 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libstack/libstack.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void *ft_itov(int n) {
    int *p;

    p = malloc(sizeof(int));
    *p = n;
    return (p);
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
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

int calculate_cost(t_stack *stack_a, t_stack *stack_b, int index, int b_index) {
    if (index < stack_a->size / 2 && b_index < stack_b->size / 2)
        return max(index, b_index);
    if (index > stack_a->size / 2 && b_index > stack_b->size / 2)
        return max(stack_a->size - index, stack_b->size - b_index);

    return min(index + (stack_b->size - b_index), b_index + (stack_a->size - index));
}

void ft_find_smallest_cost_move(t_stack *a, t_stack *b, int *a_index, int *b_index) {
    t_list *node = a->head;
    int index = 0;
    int cost = INT_MAX;
    int temp = 0;
    int small = 0;

    while (node) {
        small = ft_find_small_nearest(b, *(int *) node->content);
        temp = calculate_cost(a, b, index, small);
        if (temp < cost) {
            *a_index = index;
            *b_index = small;
            cost = temp;
        }
        index++;
        node = node->next;
    }
}

void perform_low_cost_op(t_stack *stack_a, t_stack *stack_b, int index, int b_index) {
    if (index > stack_a->size / 2 && b_index > stack_b->size / 2) {
        index = stack_a->size - index;
        b_index = stack_b->size - b_index;

        while (index > 0 && b_index > 0) {
            rrr(stack_a, stack_b);
            index--;
            b_index--;
        }
        while (index-- > 0)
            rra(stack_a);
        while (b_index-- > 0)
            rrb(stack_b);
        return;
    }

    if (index < stack_a->size / 2 && b_index < stack_b->size / 2) {
        while (index > 0 && b_index > 0) {
            rr(stack_a, stack_b);
            index--;
            b_index--;
        }
        while (index-- > 0)
            ra(stack_a);
        while (b_index-- > 0)
            rb(stack_b);
        return;
    }

    // 1 2 3 4 5

    if (index < stack_a->size / 2) {
        while (index-- > 0)
            ra(stack_a);
    } else {
        index = stack_a->size - index;
        while (index-- > 0)
            rra(stack_a);
    }

    if (b_index < stack_b->size / 2) {
        while (b_index-- > 0)
            rb(stack_b);
    } else {
        b_index = stack_b->size - b_index;
        while (b_index-- > 0)
            rrb(stack_b);
    }
}

void ft_pre_sort_stack(t_stack *a, t_stack *b) {
    int index_a = 0;
    int index_b = 0;

    if (a->size <= 3)
        return;

    if (!b->head) {
        pb(a, b);
        pb(a, b);
    }

    ft_find_smallest_cost_move(a, b, &index_a, &index_b);
    perform_low_cost_op(a, b, index_a, index_b);
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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }

    t_stack *stack_b;
    t_stack *stack_a;

    stack_b = ft_stack_new();
    stack_a = ft_stack_new();

    for (int i = argc - 1; i > 0; i--) {
        int num = atoi(argv[i]);
        ft_stack_push(stack_a, ft_itov(num));
    }

    ft_sort_stack(stack_a, stack_b);

    ft_stack_clear(&stack_a);
    ft_stack_clear(&stack_b);

    return 0;
}
