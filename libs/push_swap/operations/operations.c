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

	if (a == 0 || a->next == 0)
		return (a);
	a = stack_end(a);
	tmp = a->value;
	a->value = a->prev->value;
	a->prev->value = tmp;
	return (stack_begin(a));
}

t_ab_stack	*ft_pa(t_ab_stack *s, int partition)
{
	if (s->b == 0)
		return (s);
	s->b = stack_end(s->b);
	s->a = stack_push(s->a, s->b->value, partition);
	s->b = stack_pop(s->b);
	s->b = stack_begin(s->b);
	return (s);
}

t_ab_stack	*ft_pb(t_ab_stack *s, int partition)
{
	if (s->a == 0)
		return (s);
	s->a = stack_end(s->a);
	s->b = stack_push(s->b, s->a->value, partition);
	s->a = stack_pop(s->a);
	s->a = stack_begin(s->a);
	return (s);
}

t_stack		*ft_r(t_stack *a)
{
	int rem_last;
	int rem_last2;

	if (a == 0 || a->next == 0)
		return (a);
	a = stack_end(a);
	rem_last = a->value;
	rem_last2 = a->partition;
	while (a->prev != 0)
	{
		a->value = a->prev->value;
		a->partition = a->prev->partition;
		a = a->prev;
	}
	a->value = rem_last;
	a->partition = rem_last2;
	return (a);
}

t_stack		*ft_rr(t_stack *a)
{
	int rem_first;
	int rem_first2;

	if (a == 0 || a->next == 0)
		return (a);
	rem_first = a->value;
	rem_first2 = a->partition;
	while (a->next != 0)
	{
		a->value = a->next->value;
		a->partition = a->next->partition;
		a = a->next;
	}
	a->value = rem_first;
	a->partition = rem_first2;
	return (stack_begin(a));
}
