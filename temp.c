/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:08:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/05/18 09:38:54 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int find_nearest_smaller_index(t_stack *stack, int n) {
    t_list *node = stack->head;
    int nearest = *(int *)(node->content);
    int diff;
    int nearest_index = 0;
    int index = 0;

    while (node) {
        diff = abs(n - *(int *)(node->content));
        if (diff < abs(n - nearest) && *(int *)(node->content) < n) {
            nearest = *(int *)(node->content);
            nearest_index = index;
        }
        node = node->next;
        index++;
    }
    return nearest_index;
}

int ft_find_small_nearest(t_stack *stack, int n) {
    if(!stack->head)
      return 0;
    int nearest_index = find_nearest_smaller_index(stack, n);
    int max_index = find_max_index(stack);

    if (*(int *)(stack->head->content) < n) {
        return nearest_index;
    } else {
        return max_index;
    }
}




void ft_stack_sort(t_stack *stack_a, t_stack *stack_b) {

  int cheapest_a = 0;
  int cheapest_b = 0;
  int cheapset = 0;
  t_list *node = stack_a->head;
  int index = 0;

  while (node) {
    cheapest_a = index; 
    cheapest_b = (ft_find_small_nearest(stack_b , *(int*)(node->content)));
    // cheapset = min(stack_a->size - cheapest_a , cheapest_a) + min(stack_b->size - cheapest_b, cheapest_b);
    printf("| %d -- %d |\n" , cheapest_a , cheapest_b);
    node = node->next;
    index++;
  }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }

    t_stack *stack_b;
    t_stack *stack_a;

    stack_b = ft_stack_new();
    stack_a = ft_stack_new();

    for (int i = argc - 1 ; i > 0 ; i--) {
        int num = atoi(argv[i]);
        ft_stack_push(stack_a, ft_itov(num));
    }

    ft_sort_stack(stack_a, stack_b);

    ft_stack_clear(&stack_a);
    ft_stack_clear(&stack_b);

    return 0;
}


