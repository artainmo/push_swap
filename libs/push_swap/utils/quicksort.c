/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_median(t_stack *s, int partition)
{
	int	len;
	int	value;

	len = partition_len(s, partition);
	len = len / 2;
	value = smallest_value(s, partition);
	while (len != 0)
	{
		value = next_smallest(s, value, partition);
		len--;
	}
	return (value);
}

int	numbers_before_median(t_stack *s, int partition)
{
	return (partition_len(s, partition) / 2);
}

int	numbers_equal_after_median(t_stack *s, int partition)
{
	int len;

	len = partition_len(s, partition);
	if (len % 2 == 0)
		return (len / 2);
	else
		return (len / 2 + 1);
}
