/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:25:53 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:40:02 by franaivo         ###   ########.fr       */
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
void		nothing(void *p);

void		ft_stack_clear(t_stack **stack);
void		ft_stack_print(t_stack *stack);
void		ft_stack_rotate_reverse(t_stack *stack);
void		ft_stack_rotate(t_stack *stack);
t_stack	*ft_stack_new(void);
t_list	*ft_stack_pop(t_stack *stack);
void		ft_stack_push(t_stack *stack, void *content);
int			ft_stack_is_empty(t_stack *s);

void		p(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);

void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

void		s(t_stack *a);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

#endif // !LIBSTACK_H
