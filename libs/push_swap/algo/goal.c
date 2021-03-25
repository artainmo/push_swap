/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	verify_goal(t_goal *goal, t_stack *a, t_stack *b, int debug)
{
	if ((goal->stack == 'a' && partition_sorted_all(a, b, goal->partition)) ||
			(goal->stack == 'b' && partition_sorted_allb(b, a, goal->partition))
			|| goal->pushed_number >= goal->number_to_push)
	{
		if (goal->stack == 'a')
			next_goala(goal, a, b, debug);
		else if (goal->stack == 'b')
			next_goalb(goal, a, b, debug);
	}
}

t_goal	*init_goal(t_stack *a, int debug)
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
	return (goal);
}
