/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/16 11:16:50 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libstack/libstack.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void *ft_itov(int n) {
    int *p;

    p = malloc(sizeof(int));
    *p = n;
    return (p);
}

int min(int a , int b)
{
  if(a < b)
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

int main(void) {
    t_stack *stack_b;
    t_stack *stack_a;

    stack_b = ft_stack_new();
    stack_a = ft_stack_new();

    ft_stack_push(stack_a, ft_itov(9));

    
    ft_stack_push(stack_b, ft_itov(8));
    ft_stack_push(stack_b, ft_itov(7));
    ft_stack_push(stack_b, ft_itov(1));
    ft_stack_push(stack_b, ft_itov(2));
    ft_stack_push(stack_b, ft_itov(5));
    ft_stack_push(stack_b, ft_itov(6));

    ft_stack_print(stack_a);
    ft_stack_print(stack_b);

    printf("%d" , ft_find_small_nearest(stack_b, 9));

    ft_stack_clear(&stack_a);
    ft_stack_clear(&stack_b);

    return 0;
}
