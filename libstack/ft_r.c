/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:56:01 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/20 17:46:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void ra(t_stack *a) {
    if (ft_stack_is_empty(a))
        return;
    ft_stack_rotate(a);
    ft_putendl_fd("ra", 1);
}

void rb(t_stack *b) {
    if (ft_stack_is_empty(b))
        return;
    ft_stack_rotate(b);
    ft_putendl_fd("rb", 1);
}

void rr(t_stack *a, t_stack *b) {
    ft_stack_rotate(a);
    ft_stack_rotate(b);
    ft_putendl_fd("rr", 1);
}
