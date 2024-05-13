/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:21:37 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:41:23 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ra(t_stack *a)
{
	ft_stack_rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	ft_stack_rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a);
	ft_stack_rotate(b);
	ft_putendl_fd("rr", 1);
}
