/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	orderedb(t_stack *b)
{
	int start;

	if (b == 0)
		return (0);
	b = stack_position(b, stack_lowest_value_pos(b));
	start = b->number;
	while (b->value < stack_next(b)->value)
	{
		b = stack_next(b);
		if (stack_next(b)->number == start)
			return (1);
	}
	return (0);
}

int	ordered(t_stack *a)
{
	int start;

	if (a == 0)
		return (0);
	a = stack_position(a, stack_highest_value_pos(a));
	start = a->number;
	while (a->value > stack_next(a)->value)
	{
		a = stack_next(a);
		if (stack_next(a)->number == start)
			return (1);
	}
	return (0);
}

int	partition_sorted_all(t_stack *a, t_stack *b, int partition)
{
	int biggest_value_b;

	if (a == 0)
		return (0);
	if (partition_len(a, partition) == 0)
		return (0);
	biggest_value_b = stack_biggest_value(b);
	while (a->next != 0)
	{
		if (a->partition == partition && (a->value < a->next->value ||
			a->value < biggest_value_b))
			return (0);
		a = a->next;
	}
	if (a->partition == partition && a->value < biggest_value_b)
		return (0);
	return (1);
}

int	partition_sorted_allb(t_stack *b, t_stack *a, int partition)
{
	int smallest_value_a;

	if (b == 0)
		return (0);
	if (partition_len(b, partition) == 0)
		return (0);
	smallest_value_a = stack_smallest_value(a);
	while (b->next != 0)
	{
		if (b->partition == partition && (b->value > b->next->value ||
			b->value > smallest_value_a))
			return (0);
		b = b->next;
	}
	if (b->partition == partition && b->value > smallest_value_a)
		return (0);
	return (1);
}

int	partition_sorted(t_stack *a, int partition)
{
	if (a == 0)
		return (0);
	if (partition_len(a, partition) == 0)
		return (0);
	while (a->next != 0)
	{
		if (a->partition == partition && a->value < a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
