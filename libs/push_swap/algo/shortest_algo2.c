/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_algo2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			is_sorted(t_stack *a, t_stack *b)
{
	if (b != 0)
		return (0);
	while (a->next != 0)
	{
		if (a->value < a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int			ordered(t_stack *a)
{
	int start;

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

int			all_ordered(t_stack *a, t_stack *b)
{
	if (b != 0)
		return (0);
	return (ordered(a));
}

static int	sa_ideal(t_stack *a, t_stack *b)
{
	t_stack	*cpy;
	int		ret;

	if (b != 0)
		return (0);
	cpy = stack_copy(a);
	cpy = ft_s(cpy);
	ret = ordered(cpy);
	free_stack(cpy);
	return (ret);
}

char		*top_greater_than_second(t_stack *a, t_stack *b)
{
	if (stack_end(a)->value < stack_end(a)->prev->value)
		return (0);
	if (sa_ideal(a, b))
		return (malloc_operation("sa"));
	else if (ideal_next(stack_end(a)) != stack_next(stack_end(a))->value)
		return (malloc_operation("pb"));
	else
		return out_longest_chain(a, b, longest_chain(a));
}
