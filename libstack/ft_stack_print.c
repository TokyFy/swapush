/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:52:05 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:37:09 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ft_stack_print(t_stack *stack)
{
	ft_putstr_fd("-->  ", 1);
	ft_lstiter(stack->head, debug);
	ft_putstr_fd(" <-- [ ", 1);
	ft_putnbr_fd(stack->size, 1);
	ft_putendl_fd(" ]", 1);
}
