int find_max_index(t_stack *stack) {
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


