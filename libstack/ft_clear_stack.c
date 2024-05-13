/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:01:26 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 12:01:31 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ft_clear_stack(t_stack **stack)
{
	ft_lstclear(&(*stack)->head, free);
	free(*stack);
	*stack = NULL;
}
