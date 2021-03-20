/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_algo4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_inside_longest_chain(int value, t_stack *a, t_sorted_chain *sc)
{
	if (sc == 0)
		return (2);
	else if (value <= get_value_from_position(a, sc->start) && value >= get_value_from_position(a, sc->end))
		return (1);
	return (0);
}

/*
**If no ideal next because is smallest value -> returns itself
**which cannot be equal to another number as all are unique
*/

int	ideal_next(t_stack *a)
{
	t_stack	*i;
	int		ideal;

	i = stack_begin(a);
	ideal = a->value;
	while (i != 0)
	{
		if (a->value - i->value > 0 && (i->value > ideal || ideal == a->value))
			ideal = i->value;
		i = i->next;
	}
	if (ideal == a->value)
		return stack_biggest_value(a);
	return (ideal);
}

int	ideal_next2(t_stack *a, int value)
{
	t_stack	*i;
	int		ideal;

	i = stack_begin(a);
	ideal = value;
	while (i != 0)
	{
		if (value - i->value > 0 && (i->value > ideal || ideal == value))
			ideal = i->value;
		i = i->next;
	}
	if (ideal == value)
		return stack_biggest_value(a);
	return (ideal);
}

char		*top_greater_than_second2(t_stack *a)
{
	// t_sorted_chain *sc;

	if (stack_end(a)->value < stack_end(a)->prev->value)
		return (0);
	// sc = longest_chain(a);
	// if (sc == 0)
	// 	return (malloc_operation("sa"));
	// if (sc->end == stack_end(a)->prev->number || sc->start == stack_end(a)->number)
	// 	return out_longest_chain(a, 0, sc);
	return (malloc_operation("sa"));
}
