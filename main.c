/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 11:04:40 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    t_list *head;
    int size;
} t_stack;

t_stack *ft_stack_new() {
    t_stack *new = malloc(sizeof(t_stack));
    new->head = NULL;
    new->size = 0;
    return new;
}

void debug(void *number) {
    ft_putnbr_fd(*(int *) number, 1);
    ft_putstr_fd("  |  ", 1);
}

void ft_stack_push(t_stack *stack, void *content) {
    t_list *newTop = ft_lstnew(content);
    ft_lstadd_front(&stack->head, newTop);
    stack->size++;
}

t_list *ft_stack_pop(t_stack *stack) {
    if (!stack->head)
        return NULL;
    stack->size--;
    t_list *poped = stack->head;
    stack->head = stack->head->next;
    poped->next = NULL;
    return poped;
}

void ft_print_stack(t_stack *stack) {
    ft_putstr_fd("-->  ", 1);
    ft_lstiter(stack->head, debug);
    ft_putstr_fd(" <-- [ ", 1);
    ft_putnbr_fd(stack->size, 1);
    ft_putendl_fd(" ]", 1);
}

void ft_clear_stack(t_stack **stack) {
    ft_lstclear(&(*stack)->head, free);
    free(*stack);
    *stack = NULL;
}

void ft_rotate_stack(t_stack *stack) {
    t_list *top = ft_stack_pop(stack);
    ft_lstadd_back(&stack->head, top);
}

void ft_rotate_reverse_stack(t_stack *stack) {
    t_list *temp = stack->head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    t_list *last = temp->next;
    temp->next = NULL;
    ft_lstadd_front(&stack->head, last);
}

int is_stack_empty(t_stack *s) {
    return !(s->size);
}

//operation

void nothing(void *p) {
    return;
}

void p(t_stack *a, t_stack *b) {
    if (is_stack_empty(a))
        return;

    t_list *head_a = ft_stack_pop(a);
    ft_stack_push(b, head_a->content);
    ft_lstdelone(head_a, nothing);
}

void s(t_stack *a) {

    if (is_stack_empty(a))
        return;

    t_list *head = ft_stack_pop(a);
    t_list *head_next = ft_stack_pop(a);

    ft_stack_push(a, head->content);
    ft_stack_push(a, head_next->content);

    ft_lstdelone(head, nothing);
    ft_lstdelone(head_next, nothing);
}

void sa(t_stack *a) {
    s(a);
    ft_putendl_fd("sa", 1);
}

void sb(t_stack *b) {
    s(b);
    ft_putendl_fd("sb", 1);
}

void ss(t_stack *a, t_stack *b) {
    s(a);
    s(b);
    ft_putendl_fd("ss", 1);
}

void pa(t_stack *a, t_stack *b) {
    p(b, a);
    ft_putendl_fd("pa", 1);
}

void pb(t_stack *a, t_stack *b) {
    p(a, b);
    ft_putendl_fd("pb", 1);
}

void ra(t_stack *a) {
    ft_rotate_stack(a);
    ft_putendl_fd("ra", 1);
}

void rb(t_stack *b) {
    ft_rotate_stack(b);
    ft_putendl_fd("rb", 1);
}

void rr(t_stack *a, t_stack *b) {
    ft_rotate_stack(a);
    ft_rotate_stack(b);
    ft_putendl_fd("rr", 1);
}

void rra(t_stack *a) {
    ft_rotate_reverse_stack(a);
    ft_putendl_fd("rra", 1);
}

void rrb(t_stack *b) {
    ft_rotate_reverse_stack(b);
    ft_putendl_fd("rrb", 1);
}

void rrr(t_stack *a, t_stack *b) {
    ft_rotate_reverse_stack(a);
    ft_rotate_reverse_stack(b);
    ft_putendl_fd("rrr", 1);
}


int main() {
    t_stack *stack_b = ft_stack_new();
    t_stack *stack_a = ft_stack_new();

    for (int i = 0; i < 500; i++) {
        int *n_a = malloc(sizeof(int));
        int *n_b = malloc(sizeof(int));
        *n_a = i;
        *n_b = i * 10;
        ft_stack_push(stack_a, n_a);
        ft_stack_push(stack_b, n_b);
    };

    ft_clear_stack(&stack_a);
    ft_clear_stack(&stack_b);
}
