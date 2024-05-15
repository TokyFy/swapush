/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/15 15:48:36 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libstack/libstack.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_itov(int n)
{
	int	*p;

	p = malloc(sizeof(int));
	*p = n;
	return (p);
}

t_list	*ft_stack_max(t_stack *stack)
{
	t_list	*max;
	t_list	*i;

	max = stack->head;
	i = stack->head;
	while (i)
	{
		if (*(int *)(max->content) < *(int *)(i->content))
			max = i;
		i = i->next;
	}
	return (max);
}

void	ft_stack_sort_three(t_stack *stack_a)
{
	t_list	*max;

	if (stack_a->size <= 1 || stack_a->size > 3)
		return ;
	max = ft_stack_max(stack_a);
	if (max == stack_a->head)
		ra(stack_a);
	else if (stack_a->size > 2 && (max == stack_a->head->next))
		rra(stack_a);
	if ((*(int *)(stack_a->head->content) > *(int *)(stack_a->head->next->content)))
		sa(stack_a);
}

int ft_find_small_nearest(t_stack *stack , int n)
{
<<<<<<< HEAD
  if(stack_a->size <= 3)
    return ft_stack_sort_three(stack_a);

  int i = stack_a->size / 2;

  while (i-- > 0 ) {
    if(!inverse)
    {
      pb(stack_a , stack_b);
    }
    else {
      pa(stack_a , stack_b);
    }
  }
}

void ft_stack_merge_n(t_stack* stack_a , t_stack * stack_b , t_size_t s_a , t_size_t s_b)
{
  
}

int main() {
    t_stack *stack_b = ft_stack_new();
    t_stack *stack_a = ft_stack_new();

    // CODE
 
    ft_stack_push(stack_a, ft_itov(4));
    ft_stack_push(stack_a, ft_itov(2));
    ft_stack_push(stack_a, ft_itov(0));
=======
>>>>>>> 7c8418a8a88b36ee05cdcbb62a551288fda28445
    
  return 0;
}

void ft_stack_sort(t_stack *stack_a , t_stack *stack)
{
  int a_pos = 1;

  t_list *node = stack_a->head;

  while (node) {
    // keep N index
    // find the index of the nierest smallest items from next
    
    // keep the these number
    // calculate the min distance
  }
}

int	main(void)
{
	t_stack	*stack_b;
	t_stack	*stack_a;

	stack_b = ft_stack_new();
	stack_a = ft_stack_new();


  ft_stack_push(stack_a, ft_itov(5));
  ft_stack_push(stack_a, ft_itov(4));
  ft_stack_push(stack_a, ft_itov(3));
  ft_stack_push(stack_a, ft_itov(2));
  ft_stack_push(stack_a, ft_itov(0));
  ft_stack_push(stack_a, ft_itov(1));
	// CODE

  ft_stack_print(stack_a);
  printf("-- %d --\n" , ft_find_small_nearest(stack_a , 5));

	// CODE
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
}
