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

int			is_sortedb(t_stack *b)
{
	if (b == 0)
		return (0);
	while (b->next != 0)
	{
		if (b->value > b->next->value)
			return (0);
		b = b->next;
	}
	return (1);
}

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

int			orderedb(t_stack *b)
{
	int start;

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

// static int	sa_ideal_all(t_stack *a, t_stack *b)
// {
// 	t_stack	*cpy;
// 	int		ret;
//
// 	if (b != 0)
// 		return (0);
// 	cpy = stack_copy(a);
// 	cpy = ft_s(cpy);
// 	ret = ordered(cpy);
// 	free_stack(cpy);
// 	return (ret);
// }

int	sa_ideal(t_stack *s)
{
	if (stack_end(s)->prev->value == ideal_next2(s, stack_end(s)->value))
		return (1);
	if (ideal_next2(s, stack_end(s)->prev->value) == stack_begin(s)->value)
		return (1);
	return (0);
}

int	sa_ideal2(t_stack *s, t_sorted_chain *sc)
{
	if (s == 0 || s->next == 0 || s->next->next == 0)
		return 0;
	if (sc == 0)
		return sa_ideal(s);
	if (stack_end(s)->prev->value == ideal_next2(s, stack_end(s)->value) && stack_end(s)->prev->value == sc->end)
		return (1);
	if (ideal_next2(s, stack_end(s)->prev->value) == stack_begin(s)->value && stack_begin(s)->value == sc->start)
		return (1);
	return (0);
}
// char		*top_greater_than_second(t_stack *a, t_stack *b)
// {
// 	if (stack_end(a)->value < stack_end(a)->prev->value)
// 		return (0);
// 	if (sa_ideal(a))
// 		return (malloc_operation("sa"));
// 	else if (ideal_next(stack_end(a)) != stack_next(stack_end(a))->value)
// 		return (malloc_operation("pb"));
// 	else
// 		return out_longest_chain(a, b, longest_chain(a));
// }
