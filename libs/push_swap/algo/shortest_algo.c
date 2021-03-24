/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char		*shortest_path_to_correct_placement(t_stack *a)
{
	if (stack_end(a)->number - stack_highest_value_pos(a) + 1
			< stack_highest_value_pos(a))
		return (malloc_operation("ra"));
	else
		return (malloc_operation("rra"));
}

char		*shortest_path_to_correct_placementb(t_stack *b)
{
	if (stack_end(b)->number - stack_lowest_value_pos(b) + 1
			< stack_lowest_value_pos(b))
		return (malloc_operation("rb"));
	else
		return (malloc_operation("rrb"));
}

int	sa_ideala(t_stack *a)
{
	t_stack	*cpy;
	int		ret;
	int i;

	i = 0;
	if (a == 0 || a->next == 0 || stack_sorted(a))
		return (0);
	while (a->next != 0)
	{
		i++;
		if (i > 4)
			return (0);
		a = a->next;
	}
	a = stack_begin(a);
	cpy = stack_copy(a);
	cpy = ft_s(cpy);
	ret = ordered(cpy);
	free_stack(cpy);
	return (ret);
}

int	sa_idealb(t_stack *b)
{
	t_stack	*cpy;
	int		ret;
	int i;

	i = 0;
	if (b == 0 || b->next == 0 || stack_sortedb(b))
		return (0);
	while (b->next != 0)
	{
		i++;
		if (i > 4)
			return (0);
		b = b->next;
	}
	b = stack_begin(b);
	cpy = stack_copy(b);
	cpy = ft_s(cpy);
	ret = orderedb(cpy);
	free_stack(cpy);
	return (ret);
}
