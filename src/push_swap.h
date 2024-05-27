/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:09:57 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/27 10:53:41 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:09:57 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/20 18:37:49 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libstack/libstack.h"
# include "limits.h"

void	*ft_itov(int n);
int		min(int a, int b);
int		max(int a, int b);
char	*ft_ltoa(long i);
int		ft_is_all_digit(char *str);
int		have_duplicate(char **str);

int		find_max_index(t_stack *stack);
int		find_min_index(t_stack *stack);
int		ft_find_small_nearest(t_stack *stack, int n);
int		ft_find_big_nearest(t_stack *stack, int n);

t_list	*ft_stack_max(t_stack *stack);

int		calculate_cost(t_stack *stack_a, t_stack *stack_b, int index,
			int b_index);
void	find_smallest_cost_move(t_stack *a, t_stack *b, int *a_index,
			int *b_index);
void	execute_low_cost_move(t_stack *stack_a, t_stack *stack_b, int index,
			int b_index);

void	ft_pre_sort_stack(t_stack *a, t_stack *b);
void	ft_sort_stack(t_stack *a, t_stack *b);

void	ft_stack_sort_three(t_stack *stack_a);

#endif
