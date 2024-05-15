/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/14 14:33:45 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libstack/libstack.h"
#include <stdio.h>
#include <stdlib.h>

void * ft_itov(int n)
{
  int *p = malloc(sizeof(int));
  *p = n;
  return p;
}

t_list* ft_stack_max(t_stack* stack)
{
  t_list* max = stack->head;
  t_list* i = stack->head;

  while (i) {
    if(*(int *)(max->content) < *(int *)(i->content))
      max = i;

    i = i->next;
  }

  return max;
}

void ft_stack_sort_three(t_stack* stack_a)
{
  if(stack_a->size <= 1 || stack_a->size > 3)
    return;

  t_list *max = ft_stack_max(stack_a);

  if(max == stack_a->head)
    ra(stack_a);
  else if (stack_a->size > 2 && (max == stack_a->head->next))
    rra(stack_a);

  if((*(int *)(stack_a->head->content) > *(int *)(stack_a->head->next->content)))
    sa(stack_a);
}


void ft_stack_sort_n(t_stack* stack_a , t_stack * stack_b , t_size_t n , int inverse)
{
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
    
    ft_stack_push(stack_b, ft_itov(5));
    ft_stack_push(stack_b, ft_itov(3));
    ft_stack_push(stack_b, ft_itov(1));

    ft_stack_print(stack_a);
    ft_stack_print(stack_b);
 

    ft_stack_merge_n(stack_a, stack_b, 3, 3, 0);

    ft_stack_print(stack_a);
    ft_stack_print(stack_b);
  

    // CODE

    ft_stack_clear(&stack_a);
    ft_stack_clear(&stack_b);
}
