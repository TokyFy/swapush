/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:12:32 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/20 18:12:56 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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