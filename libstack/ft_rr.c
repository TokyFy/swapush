/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:29:03 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:42:02 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	rra(t_stack *a)
{
	ft_stack_rotate_reverse(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b)
{
	ft_stack_rotate_reverse(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_stack_rotate_reverse(a);
	ft_stack_rotate_reverse(b);
	ft_putendl_fd("rrr", 1);
}
