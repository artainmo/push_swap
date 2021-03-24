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

// static void ba(t_ab_stack *s, t_operations *o)
// {
// 	if (s->b == 0 || s->b->next == 0)
// 		return ;
// 	if (ft_strcmp(o->line, "sb") && stack_end(s->a)->prev->value < stack_end(s->a)->value)
// 	{
// 			free(o->line);
// 			o->line = malloc_operation("ss");
// 	}
// 	else if (ft_strcmp(o->line, "rb") && ft_strcmp(goto_num(get_position_from_value(s->a, ideal_nextb2(s->a, s->b)), s->a), "ra"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("rr");
// 	}
// 	else if (ft_strcmp(o->line, "rrb") && ft_strcmp(goto_num(get_position_from_value(s->a, ideal_nextb2(s->a, s->b)), s->a), "rra"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("rrr");
// 	}
// }

// static void ab(t_ab_stack *s, t_operations *o)
// {
// 	if (s->b == 0 || s->b->next == 0)
// 		return ;
// 	if (ft_strcmp(o->line, "sa") && stack_end(s->b)->prev->value > stack_end(s->b)->value)
// 	{
// 			free(o->line);
// 			o->line = malloc_operation("ss");
// 	}
// 	else if (ft_strcmp(o->line, "ra") && orderedb(s->b) && !is_sortedb(s->b) && ft_strcmp(shortest_path_to_correct_placementb(s->b), "ra"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("rr");
// 	}
// 	else if (ft_strcmp(o->line, "rra") && orderedb(s->b) && !is_sortedb(s->b) && ft_strcmp(shortest_path_to_correct_placementb(s->b), "rra"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("rrr");
// 	}
// }

// static void inf_loop_protection(t_operations *o, char *last)
// {
// 	if (last != 0 && (ft_strcmp(last, "ra") ||  ft_strcmp(last, "rr")) && ft_strcmp(o->line, "rra"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("ra");
// 	}
// 	if (last != 0 && (ft_strcmp(last, "rra") || ft_strcmp(last, "rrr")) && ft_strcmp(o->line, "ra"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("rra");
// 	}
// 	if (last != 0 && ft_strcmp(last, "pa") && ft_strcmp(o->line, "pb"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("rra");
// 	}
// 	if (last != 0 && ft_strcmp(last, "pb") && ft_strcmp(o->line, "pa"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("rra");
// 	}
// 	if (last != 0 && ft_strcmp(last, "sa") && ft_strcmp(o->line, "sa"))
// 	{
// 		free(o->line);
// 		o->line = malloc_operation("rra");
// 	}
// }

static void shortest_operation(t_ab_stack *s, t_operations *o, t_goal *goal, int debug)
{
	verify_goal(goal, s->a, s->b, debug);
	if (!stack_sorted(s->a) && ordered(s->a))
		o->line = shortest_path_to_correct_placement(s->a);
	else if (!stack_sortedb(s->b) && orderedb(s->b))
		o->line = shortest_path_to_correct_placementb(s->b);
	else if (sa_ideal(s->a))
		o->line = malloc_operation("sa");
	else if (sa_idealb(s->b))
		o->line = malloc_operation("sb");
	else if (goal->stack == 'a')
		o->line = quicksort_a(s->a, goal);
	else
		o->line = quicksort_b(s->b, goal);
}

static t_operations	*get_operations(t_ab_stack *s, int debug)
{
	char *line;
	t_operations	*o;
	t_goal *goal;

	o = init_operations();
	goal = init_goal(s->a, debug);
	while (!is_sorted(s->a, s->b))
	{
		shortest_operation(s, o, goal, debug);
		s = find_operation(s, o->line, goal->partition_to_push_to);
		if (debug)
		{
			show_stack(s, o->line, 1, 0);
			show_goal(goal, "GOAL STATE");
			if ((get_next_line(0, &line)) == -1)
				ft_error("get_next_line error");
			free(line);
		}
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
