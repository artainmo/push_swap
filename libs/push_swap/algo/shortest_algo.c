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
	{
		return (malloc_operation("ra"));
	}
	else
	{
		return (malloc_operation("rra"));
	}
}

char		*b_values_ideal_position_a(t_stack *a, t_stack *b)
{
	if (b == 0)
		return (0);
	if (a->value == ideal_next2(a, stack_end(b)->value))
		return (malloc_operation("pa"));
	return (0);
}

static char	*goto_ideal_value_top_b(t_stack *a, t_stack *b)
{
	int pos;

	pos = get_position_from_value(a, ideal_next2(a, stack_end(b)->value));
	if (pos <= stack_end(a)->number - pos + 1)
	{
		return (malloc_operation("rra"));
	}
	else
	{
		return (malloc_operation("ra"));
	}
}

/*
**First sc == 0 is in case no longest chain exists
**First two returns are in case of top a inside longest sorted chain
**Last two are in case top a outside longests sorted chain
*/

char		*out_longest_chain(t_stack *a, t_stack *b, t_sorted_chain *sc)
{
	printf("%p\n", sc);
	fflush(stdout);
	if (sc == 0)
		return (malloc_operation("rra"));
	if (sc->start > sc->end || stack_end(a)->number == sc->end)
	{
		if (stack_end(a)->number - sc->start - 1 > sc->end)
		{
			free_sorted_chain(sc->head);
			if (b != 0)
				return (goto_ideal_value_top_b(a, b));
			return (malloc_operation("rra"));
		}
		else
		{
			free_sorted_chain(sc->head);
			return (malloc_operation("ra"));
		}
	}
	if (stack_end(a)->number - sc->end - 1 < sc->start)
	{
		free_sorted_chain(sc->head);
		return (malloc_operation("rra"));
	}
	else
	{
		free_sorted_chain(sc->head);
		return (malloc_operation("ra"));
	}
}

char		*top_smaller_than_second(t_stack *a, t_stack *b)
{
	if (stack_end(a)->value > stack_end(a)->prev->value)
		return (0);
	return out_longest_chain(a, b, longest_chain(a));
}

/*
** int main()
** {
**   t_sorted_chain *sc;
**   t_stack *a;
**   t_stack *b;
**
**   if ((sc = malloc(sizeof(t_sorted_chain))) == 0)
**     ft_error("Malloc failed");
**   a = 0;
**   b = 0;
**   b = stack_push(b, 6);
**   b = stack_push(b, 10);
**   a = stack_push(a, 5);
**   a = stack_push(a, 3);
**   a = stack_push(a, 2);
**   a = stack_push(a, 1);
**   a = stack_push(a, 0);
**   show_stack(a, b, "Init", 0);
**
**   printf("FINAL: %s", top_smaller_than_second(a, b));
**
**   show_stack(a, b, "Init", 0);
** }
*/
