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

static char	*goto_ideal_value_top_b(t_stack *a, t_stack *b)
{
	int pos;

	pos = get_position_from_value(a, ideal_next2(a, stack_end(b)->value));
	if (pos <= stack_end(a)->number - pos + 1)
		return (malloc_operation("rra"));
	else
		return (malloc_operation("ra"));
}

char		*b_ideal_position_a(t_stack *a, t_stack *b, t_sorted_chain *sc)
{
	if (b == 0)
		return (0);
	if (a->value == ideal_next2(a, stack_end(b)->value) && is_inside_longest_chain(a->value, a, sc))
	{
		return (malloc_operation("pa"));
	}
	if (ideal_next2(a, stack_end(a)->value) < stack_end(b)->value && stack_end(b)->value < stack_end(a)->value && is_inside_longest_chain(stack_end(a)->value, a, sc))
	{
		return (malloc_operation("pa"));
	}
	if (ordered(a))
		return goto_ideal_value_top_b(a, b);
	return (0);
}

/*
**First sc == 0 is in case no longest chain exists
**First two returns are in case of top a inside longest sorted chain
**Last two are in case top a outside longests sorted chain
*/

// char		*out_longest_chain(t_stack *a, t_stack *b, t_sorted_chain *sc)
// {
// 	if (sc == 0)
// 		return (malloc_operation("rra"));
// 	if (sc->start > sc->end || stack_end(a)->number == sc->end)
// 	{
// 		if (stack_end(a)->number - sc->start - 1 > sc->end)
// 		{
// 			free_sorted_chain(sc->head);
// 			if (b != 0)
// 				return (goto_ideal_value_top_b(a, b));
// 			return (malloc_operation("rra"));
// 		}
// 		else
// 		{
// 			free_sorted_chain(sc->head);
// 			return (malloc_operation("ra"));
// 		}
// 	}
// 	if (sa_ideal(a))
// 		return malloc_operation("sa");
// 	else if (ideal_next(stack_end(a)) != stack_next(stack_end(a))->value)
// 		return (malloc_operation("pb"));
// 	if (stack_end(a)->number - sc->end - 1 < sc->start)
// 	{
// 		free_sorted_chain(sc->head);
// 		return (malloc_operation("rra"));
// 	}
// 	else
// 	{
// 		free_sorted_chain(sc->head);
// 		return (malloc_operation("ra"));
// 	}
// }
//
// char		*top_smaller_than_second(t_stack *a, t_stack *b)
// {
// 	if (stack_end(a)->value > stack_end(a)->prev->value)
// 		return (0);
// 	return out_longest_chain(a, b, longest_chain(a));
// }

char *closest_exit(t_stack *a, t_sorted_chain *sc)
{
	if (stack_end(a)->number - sc->start - 1 > sc->end)
		return (malloc_operation("rra"));
	else
		return (malloc_operation("ra"));
}

char *inside_longest_chain(t_stack *a, t_sorted_chain *sc)
{
	if (is_inside_longest_chain(stack_end(a)->value, a, sc) == 1)
		return closest_exit(a, sc);
	return 0;
}

char *away_longest_chain(t_stack *a, t_sorted_chain *sc)
{
	if (sc == 0)
		return malloc_operation("rra");
	if (stack_end(a)->number - sc->end - 1 < sc->start)
		return (malloc_operation("rra"));
	else
		return (malloc_operation("ra"));
}

char *outside_longest_chain(t_stack *a, t_sorted_chain *sc)
{
	if (is_inside_longest_chain(stack_end(a)->value, a, sc) == 1)
		return 0;
	if (sa_ideal2(a, sc))
		return (malloc_operation("sa"));
	return (malloc_operation("pb"));
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
