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

static void			shortest_operation(t_ab_stack *s, t_operations *o)
{
	char *ret;

	if (all_ordered(s->a, s->b))
		o->line = shortest_path_to_correct_placement(s->a);
	else if ((ret = b_values_ideal_position_a(s->a, s->b)) != 0)
		o->line = ret;
	else if ((ret = top_smaller_than_second(s->a, s->b)) != 0)
		o->line = ret;
	else if ((ret = top_greater_than_second(s->a)) != 0)
		o->line = ret;
	else
		ft_error("Error: no operation found");
}

static t_operations	*get_operations(t_ab_stack *s)
{
	t_operations	*o;

	o = init_operations();
	while (!is_sorted(s->a, s->b))
	{
		shortest_operation(s, o);
		s = find_operation(s, o->line);
		o->s = ab_stack_copy(s);
		if ((o->next = malloc(sizeof(t_operations))) == 0)
			ft_error("Malloc failed");
		o->next->head = o->head;
		o = o->next;
		o->next = 0;
	}
	free_ab_stack(s);
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
	o = get_operations(s);
	show_operations(o->head, bonus.visual, bonus.color);
	free_operations(o->head);
	return (0);
}
