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

static void ab(t_ab_stack *s, t_operations *o)
{
	if (s->b == 0 || s->b->next == 0)
		return ;
	if (ft_strcmp(o->line, "sa") && stack_end(s->b)->prev->value > stack_end(s->b)->value)
	{
			free(o->line);
			o->line = malloc_operation("ss");
	}
	else if (ft_strcmp(o->line, "ra") && orderedb(s->b) && !is_sortedb(s->b) && ft_strcmp(shortest_path_to_correct_placementb(s->b), "ra"))
	{
		free(o->line);
		o->line = malloc_operation("rr");
	}
	else if (ft_strcmp(o->line, "rra") && orderedb(s->b) && !is_sortedb(s->b) && ft_strcmp(shortest_path_to_correct_placementb(s->b), "rra"))
	{
		free(o->line);
		o->line = malloc_operation("rrr");
	}
}

static void inf_loop_protection(t_operations *o, char *last)
{
	if (last != 0 && (ft_strcmp(last, "ra") ||  ft_strcmp(last, "rr")) && ft_strcmp(o->line, "rra"))
	{
		free(o->line);
		o->line = malloc_operation("ra");
	}
	if (last != 0 && (ft_strcmp(last, "rra") || ft_strcmp(last, "rrr")) && ft_strcmp(o->line, "ra"))
	{
		free(o->line);
		o->line = malloc_operation("rra");
	}
	if (last != 0 && ft_strcmp(last, "pa") && ft_strcmp(o->line, "pb"))
	{
		free(o->line);
		o->line = malloc_operation("rra");
	}
	if (last != 0 && ft_strcmp(last, "pb") && ft_strcmp(o->line, "pa"))
	{
		free(o->line);
		o->line = malloc_operation("rra");
	}
	if (last != 0 && ft_strcmp(last, "sa") && ft_strcmp(o->line, "sa"))
	{
		free(o->line);
		o->line = malloc_operation("rra");
	}
}

/*
** First created algorithm consisted of
** top_greater_than_second2 -> top_greater_than_second
*/

static char			*shortest_operation(t_ab_stack *s, t_operations *o, char *last)
{
	char *ret;
	t_sorted_chain *sc;

	sc = longest_chain(s->a);
	if (all_ordered(s->a, s->b))
		o->line = shortest_path_to_correct_placement(s->a);
	else if ((ret = b_ideal_position_a(s->a, s->b, sc)) != 0)
		o->line = ret;
	else if (sa_ideal2(s->a, sc))
		o->line  = malloc_operation("sa");
	else if ((ret = fill_b(s->a, s->b, sc)) != 0)
		o->line = ret;
	else
		ft_error("Error: no operation found");
	free_sorted_chain(sc);
	inf_loop_protection(o, last);
	ab(s, o);
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
