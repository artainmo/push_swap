/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		stack_biggest_value(t_stack *a)
{
	t_stack	*i;
	int		biggest;

	if (a == 0)
		return (0);
	i = stack_begin(a);
	biggest = i->value;
	while (i != 0)
	{
		if (biggest < i->value)
			biggest = i->value;
		i = i->next;
	}
	return (biggest);
}

int		stack_highest_value_pos(t_stack *s)
{
	int	big;
	int	num;

	big = -2147483648;
	num = -2147483648;
	s = stack_begin(s);
	while (s != 0)
	{
		if (s->value > big)
		{
			big = s->value;
			num = s->number;
		}
		s = s->next;
	}
	return (num);
}

int		stack_lowest_value_pos(t_stack *s)
{
	int	small;
	int	num;

	small = 2147483647;
	num = 2147483647;
	s = stack_begin(s);
	while (s != 0)
	{
		if (s->value < small)
		{
			small = s->value;
			num = s->number;
		}
		s = s->next;
	}
	return (num);
}

t_stack	*stack_next(t_stack *s)
{
	if (s->next == 0)
		return (stack_begin(s));
	else
		return (s->next);
}

t_stack	*stack_copy(t_stack *a)
{
	t_stack *cpy;

	cpy = 0;
	while (a != 0)
	{
		cpy = stack_push(cpy, a->value, a->partition);
		a = a->next;
	}
	return (cpy);
}
