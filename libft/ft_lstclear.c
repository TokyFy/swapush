/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:44:46 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/11 16:40:24 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!*lst)
		return ;
	del((*lst)->content);
    (*lst)->content = NULL;
	ft_lstclear(&((*lst)->next), del);
	free(*lst);
	*lst = 0;
}
