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

int			orderedb(t_stack *b)
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

int			ordered(t_stack *a)
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
