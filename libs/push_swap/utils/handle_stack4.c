/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	smallest_value(t_stack *s, int partition)
{
	int	small;

	small = 2147483647;
	while (s != 0)
	{
		if (s->partition == partition && s->value < small)
			small = s->value;
		s = s->next;
	}
	return (small);
}

int	next_smallest(t_stack *s, int value, int partition)
{
	t_stack	*i;
	int		ideal;

	i = stack_begin(s);
	ideal = value;
	while (i != 0)
	{
		if (i->partition == partition && value - i->value < 0 &&
				(i->value < ideal || ideal == value))
			ideal = i->value;
		i = i->next;
	}
	return (ideal);
}

int	partition_len(t_stack *stack, int partition)
{
	int	i;

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
