/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:43:34 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack/libstack.h"

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

    rra(stack_b);
    rrb(stack_a);
  

    ft_stack_clear(&stack_a);
    ft_stack_clear(&stack_b);
}
