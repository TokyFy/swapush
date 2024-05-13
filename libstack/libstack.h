/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:25:53 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 12:25:55 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTACK_H
# define LIBSTACK_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct stack
{
	t_list	*head;
	int		size;
}			t_stack;

void		debug(void *number);

void		ft_clear_stack(t_stack **stack);
void		ft_print_stack(t_stack *stack);
void		ft_rotate_reverse_stack(t_stack *stack);
void		ft_rotate_stack(t_stack *stack);
t_stack		*ft_stack_new(void);
t_list		*ft_stack_pop(t_stack *stack);
void		ft_stack_push(t_stack *stack, void *content);
int			is_stack_empty(t_stack *s);

#endif // !LIBSTACK_H
