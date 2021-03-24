/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/23 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int partition_len(t_stack *stack, int partition)
{
  int i;

  i = 0;
  if (stack == 0)
		return (0);
	while (stack != 0 && stack->partition != partition + 1)
  {
    if (stack->partition == partition)
      i++;
		stack = stack->next;
  }
  return (i);
}

int find_median(t_stack *s, int partition)
{
  int len;
  int value;

  len = partition_len(s, partition);
  len = len / 2;
  value = smallest_value(s, partition);
  while (len != 0)
  {
    value = next_smallest(s, value, partition);
    len--;
  }
  return value;
}

int numbers_before_median(t_stack *s, int partition)
{
  return partition_len(s, partition) / 2;
}

int numbers_equal_after_median(t_stack *s, int partition)
{
  int len;

  len = partition_len(s, partition);
  if (len % 2 == 0)
    return len / 2;
  else
    return len / 2 + 1;
}

static void midpoint_algo(t_goal *goal, t_stack *a, t_stack *b, int debug)
{
  if (goal->partition > 0 && partition_len(a, goal->partition) == 0)
    goal->partition -= 1;
  goal->median = find_median(a, goal->partition);
  if (goal->stack == 'a')
    goal->number_to_push = numbers_before_median(a, goal->partition);
  else
    goal->number_to_push = numbers_equal_after_median(a, goal->partition);
  goal->partition_to_push_to = stack_end(b)->partition + 1;
  goal->pushed_number = 0;
  goal->returned_number = 0;
  goal->returning = 0;
  if (debug == 1)
    show_goal(goal, "NEW GOAL");
}

static void midpoint_algo_s_change(t_goal *goal, char st, t_stack *s, int d)
{
  goal->stack = st;
  goal->partition = stack_end(s)->partition;
  goal->median = find_median(s, goal->partition);
  if (goal->stack == 'a')
    goal->number_to_push = numbers_before_median(s, goal->partition);
  else
    goal->number_to_push = numbers_equal_after_median(s, goal->partition);
  goal->partition_to_push_to = 0;
  goal->pushed_number = 0;
  goal->returned_number = 0;
  goal->returning = 0;
  if (d == 1)
    show_goal(goal, "NEW GOAL");
}

static void next_goalb(t_goal *goal, t_stack *a, t_stack *b, int debug)
{
  if (goal->returned_number != 0 && goal->partition != 0)
  {
    goal->returning = 1;
    return ;
  }
  else
    goal->returning = 0;
  if (goal->all_ordered_push != 0)
    return ;
  if (partition_sortedb(b, goal->partition))
  {
    goal->all_ordered_push = partition_len(b, goal->partition);
    return ;
  }
  if (goal->partition == 0 && stack_len(b) == 0)
  {
      midpoint_algo_s_change(goal, 'a', a, debug);
      if (partition_sortedb(b, goal->partition))
        goal->all_ordered_push = partition_len(b, goal->partition);
      return ;
  }
  if (partition_len(b, goal->partition) == 2 || partition_len(b, goal->partition) == 1)
    return ;
  midpoint_algo(goal, b, a, debug);
}

static void next_goala(t_goal *goal, t_stack *a, t_stack *b, int debug)
{
  if (goal->returned_number != 0 && goal->partition != 0)
  {
    goal->returning = 1;
    return ;
  }
  else
    goal->returning = 0;
  if (goal->all_ordered_push != 0 && goal->partition != 0)
    return ;
  if (goal->partition != 0 && partition_sorted(a, goal->partition))
  {
    goal->all_ordered_push = partition_len(a, goal->partition);
    return ;
  }
  if ((stack_len(a) == 2) && stack_end(a)->value > stack_begin(a)->value)
    return ;
  if (goal->partition == 0 && (stack_len(a) <= 2 || stack_sorted(a)))
  {
    midpoint_algo_s_change(goal, 'b', b, debug);
    if (goal->partition != 0 && partition_sorted(a, goal->partition))
      goal->all_ordered_push = partition_len(a, goal->partition);
    return ;
  }
  if (partition_len(a, goal->partition) == 2 || partition_len(a, goal->partition) == 1)
    return ;
  midpoint_algo(goal, a, b, debug);
}

void verify_goal(t_goal *goal, t_stack *a, t_stack *b, int debug)
{
  if ((goal->stack == 'a' && partition_sorted(a, goal->partition)) || (goal->stack == 'b' && partition_sortedb(b, goal->partition)) || goal->pushed_number >= goal->number_to_push)
  {
    if (goal->stack == 'a')
      next_goala(goal, a, b, debug);
    else if (goal->stack == 'b')
      next_goalb(goal, a, b, debug);
  }
}

t_goal *init_goal(t_stack *a, int debug)
{
  t_goal *goal;

  if ((goal = malloc(sizeof(t_goal))) == 0)
    ft_error("Malloc2 failed");
  goal->stack = 'a';
  goal->partition = 0;
  goal->partition_to_push_to = 0;
  goal->median = find_median(a, goal->partition);
  goal->number_to_push = numbers_before_median(a, goal->partition);
  goal->pushed_number = 0;
  goal->returned_number = 0;
  if (debug == 1)
    show_goal(goal, "NEW GOAL");
  return goal;
}

char *quicksort_a(t_stack *a, t_goal *goal)
{
  int len;

  len = partition_len(a, goal->partition);
  a = partition_end(a, goal->partition);
  if (goal->returning)
  {
    goal->returned_number -= 1;
    return malloc_operation("rra");
  }
  if (goal->all_ordered_push)
  {
    goal->all_ordered_push -= 1;
    goal->pushed_number++;
    return malloc_operation("pb");
  }
  if (len == 1)
  {
    goal->pushed_number++;
    return malloc_operation("pb");
  }
  else if (len == 2 && a->value < a->prev->value)
  {
    goal->pushed_number++;
    return malloc_operation("pb");
  }
  else if (len == 2 && a->value > a->prev->value)
    return malloc_operation("sa");
  else if (a->value < goal->median && a->value > a->prev->value)
    return malloc_operation("sa");
  else if (a->value < goal->median)
  {
    goal->pushed_number++;
    return malloc_operation("pb");
  }
  else if (stack_next(a)->value < goal->median && stack_next(a)->partition == goal->partition)
  {
    return malloc_operation("rra");
  }
  else
  {
    goal->returned_number++;
    return malloc_operation("ra");
  }
}


char *quicksort_b(t_stack *b, t_goal *goal)
{
  int len;

  len = partition_len(b, goal->partition);
  b = partition_end(b, goal->partition);
  if (goal->returning)
  {
    goal->returned_number -= 1;
    return malloc_operation("rrb");
  }
  if (goal->all_ordered_push)
  {
    goal->all_ordered_push -= 1;
    goal->pushed_number++;
    return malloc_operation("pa");
  }
  if (len == 1)
  {
    goal->pushed_number++;
    return malloc_operation("pa");
  }
  else if (len == 2 && b->value > b->prev->value)
  {
    goal->pushed_number++;
    return malloc_operation("pa");
  }
  else if (len == 2 && b->value < b->prev->value)
    return malloc_operation("sb");
  else if (b->value >= goal->median && b->value < b->prev->value)
    return malloc_operation("sb");
  else if (b->value >= goal->median)
  {
    goal->pushed_number++;
    return malloc_operation("pa");
  }
  else if (stack_next(b)->value >= goal->median && stack_next(b)->partition == goal->partition)
    return malloc_operation("rrb");
  else
  {
    goal->returned_number++;
    return malloc_operation("rb");
  }
}
