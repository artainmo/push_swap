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

static char	*quicksort_a2(t_stack *a, t_goal *goal, int len)
{
	if (len == 2 && a->value < a->prev->value)
	{
		goal->pushed_number++;
		return (malloc_operation("pb"));
	}
	else if (len == 2 && a->value > a->prev->value)
		return (malloc_operation("sa"));
	else if (a->value < goal->median && a->value > a->prev->value)
		return (malloc_operation("sa"));
	else if (a->value < goal->median)
	{
		goal->pushed_number++;
		return (malloc_operation("pb"));
	}
	else if (stack_next(a)->value < goal->median &&
			stack_next(a)->partition == goal->partition)
	{
		return (malloc_operation("rra"));
	}
	else
	{
		goal->returned_number++;
		return (malloc_operation("ra"));
	}
}

char		*quicksort_a(t_stack *a, t_goal *goal)
{
	int len;

	len = partition_len(a, goal->partition);
	a = partition_end(a, goal->partition);
	if (goal->returning)
	{
		goal->returned_number -= 1;
		return (malloc_operation("rra"));
	}
	if (goal->all_ordered_push)
	{
		goal->all_ordered_push -= 1;
		goal->pushed_number++;
		return (malloc_operation("pb"));
	}
	if (len == 1)
	{
		goal->pushed_number++;
		return (malloc_operation("pb"));
	}
	return (quicksort_a2(a, goal, len));
}

static char	*quicksort_b2(t_stack *b, t_goal *goal, int len)
{
	if (len == 2 && b->value > b->prev->value)
	{
		goal->pushed_number++;
		return (malloc_operation("pa"));
	}
	else if (len == 2 && b->value < b->prev->value)
		return (malloc_operation("sb"));
	else if (b->value >= goal->median && b->value < b->prev->value)
		return (malloc_operation("sb"));
	else if (b->value >= goal->median)
	{
		goal->pushed_number++;
		return (malloc_operation("pa"));
	}
	else if (stack_next(b)->value >= goal->median &&
			stack_next(b)->partition == goal->partition)
		return (malloc_operation("rrb"));
	else
	{
		goal->returned_number++;
		return (malloc_operation("rb"));
	}
}

char		*quicksort_b(t_stack *b, t_goal *goal)
{
	int len;

	len = partition_len(b, goal->partition);
	b = partition_end(b, goal->partition);
	if (goal->returning)
	{
		goal->returned_number -= 1;
		return (malloc_operation("rrb"));
	}
	if (goal->all_ordered_push)
	{
		goal->all_ordered_push -= 1;
		goal->pushed_number++;
		return (malloc_operation("pa"));
	}
	if (len == 1)
	{
		goal->pushed_number++;
		return (malloc_operation("pa"));
	}
	return (quicksort_b2(b, goal, len));
}
