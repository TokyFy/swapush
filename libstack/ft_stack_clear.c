/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:01:26 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:36:46 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ft_stack_clear(t_stack **stack)
{
	ft_lstclear(&(*stack)->head, free);
	free(*stack);
	*stack = NULL;
}
