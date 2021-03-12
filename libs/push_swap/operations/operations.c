/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack		*ft_s(t_stack *a)
{
	int tmp;

	if (a == 0)
		return (a);
	a = stack_end(a);
	tmp = a->value;
	a->value = a->prev->value;
	a->prev->value = tmp;
	return (stack_begin(a));
}

t_ab_stack	*ft_pa(t_ab_stack *s)
{
	if (s->b == 0)
		return (s);
	s->b = stack_end(s->b);
	s->a = stack_push(s->a, s->b->value);
	s->b = stack_pop(s->b);
	s->b = stack_begin(s->b);
	return (s);
}

t_ab_stack	*ft_pb(t_ab_stack *s)
{
	if (s->a == 0)
		return (s);
	s->a = stack_end(s->a);
	s->b = stack_push(s->b, s->a->value);
	s->a = stack_pop(s->a);
	s->a = stack_begin(s->a);
	return (s);
}

t_stack		*ft_r(t_stack *a)
{
	int rem_last;

	if (a == 0)
		return (a);
	a = stack_end(a);
	rem_last = a->value;
	while (a->prev != 0)
	{
		a->value = a->prev->value;
		a = a->prev;
	}
	a->value = rem_last;
	return (a);
}

t_stack		*ft_rr(t_stack *a)
{
	int rem_first;

	if (a == 0)
		return (a);
	rem_first = a->value;
	while (a->next != 0)
	{
		a->value = a->next->value;
		a = a->next;
	}
	a->value = rem_first;
	return (stack_begin(a));
}
