/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	midpoint_algo(t_goal *goal, t_stack *a, t_stack *b, int debug)
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

static int	verify_returned_number(t_goal *goal)
{
	if (goal->returned_number != 0 && goal->partition != 0)
	{
		goal->returning = 1;
		return (0);
	}
	else
		goal->returning = 0;
	return (1);
}

static void	midpoint_algo_s_change(t_goal *goal, char st, t_stack *s, int d)
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

void		next_goalb(t_goal *goal, t_stack *a, t_stack *b, int debug)
{
	if (verify_returned_number(goal) == 0)
		return ;
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
	if (partition_len(b, goal->partition) == 2 ||
			partition_len(b, goal->partition) == 1)
		return ;
	midpoint_algo(goal, b, a, debug);
}

void		next_goala(t_goal *goal, t_stack *a, t_stack *b, int debug)
{
	if (verify_returned_number(goal) == 0)
		return ;
	if (goal->all_ordered_push != 0 && goal->partition != 0)
		return ;
	if (goal->partition != 0 && partition_sorted(a, goal->partition) &&
			!stack_sorted_all(a, b))
	{
		goal->all_ordered_push = partition_len(a, goal->partition);
		return ;
	}
	if ((stack_len(a) == 2) && stack_end(a)->value > stack_begin(a)->value)
		return ;
	if ((goal->partition == 0 && stack_len(a) <= 2) || stack_sorted_all(a, b))
	{
		midpoint_algo_s_change(goal, 'b', b, debug);
		if (goal->partition != 0 && partition_sorted(a, goal->partition))
			goal->all_ordered_push = partition_len(a, goal->partition);
		return ;
	}
	if (partition_len(a, goal->partition) == 2 ||
			partition_len(a, goal->partition) == 1)
		return ;
	midpoint_algo(goal, a, b, debug);
}
