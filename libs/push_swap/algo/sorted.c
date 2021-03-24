/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
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

int		stack_sortedb(t_stack *b)
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

int		stack_sorted(t_stack *a)
{
	if (a == 0)
		return (0);
	while (a->next != 0)
	{
		if (a->value < a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int		partition_sorted(t_stack *a, int partition)
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

int		partition_sortedb(t_stack *a, int partition)
{
	if (a == 0)
		return (0);
	if (partition_len(a, partition) == 0)
		return (0);
	while (a->next != 0)
	{
		if (a->partition == partition && a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
