/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:05:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/17 13:49:16 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libstack/libstack.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void *ft_itov(int n) {
    int *p;

    p = malloc(sizeof(int));
    *p = n;
    return (p);
}

int min(int a , int b)
{
  if(a < b)
    return a;
  return b;
}

t_list *ft_stack_max(t_stack *stack) {
    t_list *max;
    t_list *i;

    max = stack->head;
    i = stack->head;
    while (i) {
        if (*(int *) (max->content) < *(int *) (i->content))
            max = i;
        i = i->next;
    }
    return (max);
}

void ft_stack_sort_three(t_stack *stack_a) {
    t_list *max;

    if (stack_a->size <= 1 || stack_a->size > 3)
        return;
    max = ft_stack_max(stack_a);
    if (max == stack_a->head)
        ra(stack_a);
    else if (stack_a->size > 2 && (max == stack_a->head->next))
        rra(stack_a);
    if ((*(int *) (stack_a->head->content) > *(int *)(stack_a->head->next->content)))
        sa(stack_a);
}

int find_max_index(t_stack *stack) {
    if(!stack->head)
      return 0;
    t_list *node = stack->head;
    int max_num = *(int *)(node->content);
    int max_index = 0;
    int index = 0;

    while (node) {
        if (*(int *)(node->content) > max_num) {
            max_num = *(int *)(node->content);
            max_index = index;
        }
        node = node->next;
        index++;
    }
    return max_index;
}

int find_min_index(t_stack *stack) {
    if (!stack->head)
        return 0;

    t_list *node = stack->head;
    int min_num = *(int *)(node->content);
    int min_index = 0;
    int index = 0;

    while (node) {
        if (*(int *)(node->content) < min_num) {
            min_num = *(int *)(node->content);
            min_index = index;
        }
        node = node->next;
        index++;
    }

    return min_index;
}

int ft_find_small_nearest(t_stack *stack , int n)
{
  t_list *node = stack->head;
  int diff = INT_MAX;
  int temp = 0;
  int nearest = 0;
  int index = 0;

  while (node) {
    temp = n - *(int *)(node->content);
    if(temp > 0 && temp < diff)
    {
      diff = temp;
      nearest = index;
    }
    index++;
    node = node->next;
  }
  if(diff == INT_MAX)
    return find_max_index(stack);
  return nearest;
}

int ft_find_big_nearest(t_stack *stack, int n)
{
  t_list *node = stack->head;
  int diff = INT_MAX;
  int temp = 0;
  int nearest = 0;
  int index = 0;

  while (node) {
    temp = *(int *)(node->content) - n;
    if(temp > 0 && temp < diff)
    {
      diff = temp;
      nearest = index;
    }
    index++;
    node = node->next;
  }
  if(diff == INT_MAX)
    return find_min_index(stack);
  return nearest;
}

void ft_find_smallest_cost_move(t_stack *a , t_stack *b , int *a_index , int *b_index)
{
  t_list *node = a->head;
  int index = 0;
  int cost = INT_MAX;
  int temp = 0;

   while (node) {
      // TODO optimize this
      temp = ft_find_small_nearest(b, *(int*)node->content); 
      temp = min(index, a->size - index) + min(temp, b->size - temp);
      if(temp < cost)
      {
        *a_index = index;
        *b_index = temp - index;
        cost = temp;
      }
      index++;
      node = node->next;
   }
 }

void ft_pre_sort_stack(t_stack *a , t_stack *b)
{
  int index_a = 0;
  int index_b = 0;

  if(a->size <= 3)
    return;

  if(!b->head)
  {
    pb(a , b);
    pb(a , b);
  }

  ft_find_smallest_cost_move(a, b, &index_a , &index_b);

  while(index_a--)
    ra(a);

  while (index_b--)
    rb(b);

  pb(a, b);
  ft_pre_sort_stack(a, b);
}

void ft_sort_stack(t_stack *a , t_stack *b)
{
  int temp = 0;
  ft_pre_sort_stack(a, b);

  if(a->size == 3)
    ft_stack_sort_three(a);
  
  t_list *node = b->head;
  
  while (node) {
   node = b->head;
   if(!node)
      break;
   temp = ft_find_big_nearest(a, *(int *)(node->content));

    while (temp-- > 0) {
      ra(a);
    }
    pa(a, b);
  }
}

int main(void) {
    t_stack *stack_b;
    t_stack *stack_a;

    stack_b = ft_stack_new();
    stack_a = ft_stack_new();

    ft_stack_push(stack_a, ft_itov(8));
    ft_stack_push(stack_a, ft_itov(5));
    ft_stack_push(stack_a, ft_itov(6));
    ft_stack_push(stack_a, ft_itov(3));
    ft_stack_push(stack_a, ft_itov(1));
    ft_stack_push(stack_a, ft_itov(2));
   
    ft_stack_print(stack_a);
    ft_stack_print(stack_b);  

    ft_sort_stack(stack_a, stack_b);

    ft_stack_print(stack_a);
    ft_stack_print(stack_b);  

    ft_stack_clear(&stack_a);
    ft_stack_clear(&stack_b);

    return 0;
}
