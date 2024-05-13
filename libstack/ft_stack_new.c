/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:23 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 12:00:40 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

t_stack	*ft_stack_new(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->head = NULL;
	new->size = 0;
	return (new);
}
