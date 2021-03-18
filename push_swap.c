/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

static void inf_loop_protection(t_ab_stack *s, t_operations *o, char *last)
{
	if (last != 0 && ft_strcmp(last, "ra") && ft_strcmp(o->line, "rra"))
	{
		free(o->line);
		o->line = malloc_operation("ra");
	}
	else if (last != 0 && ft_strcmp(last, "rra") && ft_strcmp(o->line, "ra"))
	{
		free(o->line);
		o->line = malloc_operation("rra");
	}
	else if (last != 0 && ft_strcmp(last, "pa") && ft_strcmp(o->line, "pb"))
	{
		free(o->line);
		o->line = out_longest_chain(s->a, s->b, longest_chain(s->a));
	}
	else if (last != 0 && ft_strcmp(last, "pb") && ft_strcmp(o->line, "pa"))
	{
		free(o->line);
		o->line = out_longest_chain(s->a, s->b, longest_chain(s->a));
	}
}

/*
** First created algorithm consisted of
** top_greater_than_second2 -> top_greater_than_second
*/

static char			*shortest_operation(t_ab_stack *s, t_operations *o, char *last)
{
	char *ret;

	if (all_ordered(s->a, s->b))
		o->line = shortest_path_to_correct_placement(s->a);
	else if ((ret = b_values_ideal_position_a(s->a, s->b)) != 0)
		o->line = ret;
	else if ((ret = top_smaller_than_second(s->a, s->b)) != 0)
		o->line = ret;
	else if ((ret = top_greater_than_second(s->a, s->b)) != 0)
		o->line = ret;
	else
		ft_error("Error: no operation found");
	inf_loop_protection(s, o, last);
	return o->line;
}

static t_operations	*get_operations(t_ab_stack *s, int debug)
{
	char *line;
	t_operations	*o;
	char *last;

	o = init_operations();
	last = 0;
	while (!is_sorted(s->a, s->b))
	{
		last = shortest_operation(s, o, last);
		s = find_operation(s, o->line);
		if (debug)
		{
			show_stack(s, o->line, 1, 0);
			if ((get_next_line(0, &line)) == -1)
				ft_error("get_next_line error");
			free(line);
		}
		o->s = ab_stack_copy(s);
		if ((o->next = malloc(sizeof(t_operations))) == 0)
			ft_error("Malloc failed");
		o->next->head = o->head;
		o = o->next;
		o->next = 0;
	}
	return (o);
}

int					main(int argc, char **argv)
{
	t_ab_stack		*s;
	t_operations	*o;
	t_bonus			bonus;

	s = init_ab_stack(0, 0);
	bonus.visual = 0;
	bonus.color = 0;
	argv = verify_bonuses(&argc, argv, &bonus);
	if (argc == 1)
		exit(1);
	verify_number_errors(argc, argv);
	while (argc > 1)
	{
		s->a = stack_push(s->a, ft_atoi(argv[argc - 1]));
		argc--;
	}
	verify_duplicates(s->a);
	show_stack(s, "Init", bonus.visual, 0);
	o = get_operations(s, bonus.live);
	free_ab_stack(s);
	show_operations(o->head, bonus.visual, bonus.color);
	free_operations(o->head);
	return (0);
}
