/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:08:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/18 21:03:17 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libstack/libstack.h"

void *ft_itov(int n) {
    int *p;

    p = malloc(sizeof(int));
    *p = n;
    return (p);
}

int main() {
    t_stack *a = ft_stack_new();
    t_stack *b = ft_stack_new();



    ft_stack_push(a, ft_itov(2));
    ft_stack_push(a, ft_itov(1));
    ft_stack_push(a, ft_itov(3));

    ft_stack_push(b, ft_itov(3));
    ft_stack_push(b, ft_itov(3));

    ft_stack_print(a);
    ft_stack_print(b);
    ft_putstr_fd("__________________________\n", 1);

    rr(a , b);


    ft_stack_print(a);
    ft_stack_print(b);

}