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
	else if (ft_strcmp(o->line, "sa") && stack_end(s->b)->prev->value > stack_end(s->b)->value)
	{
			free(o->line);
			o->line = malloc_operation("ss");
	}
	else if (s->a == 0 || s->a->next == 0)
		return ;
	else if (ft_strcmp(o->line, "sb") && stack_end(s->a)->prev->value < stack_end(s->a)->value)
	{
				free(o->line);
				o->line = malloc_operation("ss");
	}
}

static void shortest_operation(t_ab_stack *s, t_operations *o, t_goal *goal, int debug)
{
	verify_goal(goal, s->a, s->b, debug);
	if (!stack_sorted(s->a) && ordered(s->a))
		o->line = shortest_path_to_correct_placement(s->a);
	else if (!stack_sortedb(s->b) && orderedb(s->b))
		o->line = shortest_path_to_correct_placementb(s->b);
	else if (sa_ideala(s->a))
		o->line = malloc_operation("sa");
	else if (sa_idealb(s->b))
		o->line = malloc_operation("sb");
	else if (goal->stack == 'a')
		o->line = quicksort_a(s->a, goal);
	else
		o->line = quicksort_b(s->b, goal);
	ab(s, o);
}

static void ft_debug(t_ab_stack *s, t_operations *o, t_goal *goal)
{
	char *line;

	show_stack(s, o->line, 1, 0);
	show_goal(goal, "GOAL STATE");
	if ((get_next_line(0, &line)) == -1)
		ft_error("get_next_line error");
	free(line);
}

static t_operations	*get_operations(t_ab_stack *s, int debug)
{
	t_operations	*o;
	t_goal *goal;

	o = init_operations();
	goal = init_goal(s->a, debug);
	while (!is_sorted(s->a, s->b))
	{
		shortest_operation(s, o, goal, debug);
		s = find_operation(s, o->line, goal->partition_to_push_to);
		if (debug)
			ft_debug(s, o, goal);
		o->s = ab_stack_copy(s);
		if ((o->next = malloc(sizeof(t_operations))) == 0)
			ft_error("Malloc14 failed");
		o->next->head = o->head;
		o = o->next;
		o->next = 0;
	}
	free(goal);
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
		s->a = stack_push(s->a, ft_atoi(argv[argc - 1]), 0);
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
