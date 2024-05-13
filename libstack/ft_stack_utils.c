/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:24:59 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 14:18:41 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	debug(void *number)
{
	ft_putnbr_fd(*(int *)number, 1);
	ft_putstr_fd("  |  ", 1);
}

void	nothing(void *p)
{
	(void)(p);
	return ;
}
