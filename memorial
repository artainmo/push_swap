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
// char		*shortest_path_to_correct_placementb(t_stack *a)
// {
// 	if (stack_end(a)->number - stack_highest_value_pos(a) + 1
// 			< stack_highest_value_pos(a))
// 	{
// 		return (malloc_operation("rra"));
// 	}
// 	else
// 	{
// 		return (malloc_operation("ra"));
// 	}
// }
//
// char	*goto_ideal_value_top_b(t_stack *a, t_stack *b)
// {
// 	int pos;
//
// 	pos = get_position_from_value(a, ideal_nextb2(a, b));
// 	if (pos <= stack_end(a)->number - pos + 1)
// 		return (malloc_operation("rra"));
// 	else
// 		return (malloc_operation("ra"));
// }
//
// char		*b_ideal_position_a(t_stack *a, t_stack *b)
// {
// 	// if (sc != 0)
// 	// {
// 	// 	printf("sc: %i %i\n", get_value_from_position(a, sc->start), get_value_from_position(a, sc->end));
// 	// 	fflush(stdout);
// 	// }
// 	// printf("1: %i %i %i %i\n", stack_end(b)->value, ideal_next2(a, stack_end(b)->value), a->value, is_inside_longest_chain(a->value, a, sc));
// 	// fflush(stdout);
// 	if (a->value == ideal_next2(a, stack_end(b)->value))
// 	{
// 		return (malloc_operation("pa"));
// 	}
// 	// printf("2: %i %i\n", stack_end(a)->value, ideal_next2(a, stack_end(a)->value));
// 	// fflush(stdout);
// 	if (ideal_next2(a, stack_end(a)->value) < stack_end(b)->value && stack_end(b)->value < stack_end(a)->value)
// 	{
// 		return (malloc_operation("pa"));
// 	}
// 	return goto_ideal_value_top_b(a, b);
// }
//
// char *goto_num(int pos, t_stack *a)
// {
// 	// printf("gtn: %i %i\n", pos + 1, stack_end(a)->number - pos);
// 	// fflush(stdout);
// 	if (stack_end(a)->number == pos)
// 		return 0;
// 	if (pos + 1 <= stack_end(a)->number - pos)
// 		return (malloc_operation("rra"));
// 	else
// 		return (malloc_operation("ra"));
// }
//
// char *fill_b(t_stack *a, t_goal *goal)
// {
// 	int value;
// 	int pos_value;
// 	int pos_goal;
// 	int dist;
//
// 	if (goal->goal == stack_end(a)->value)
// 	{
// 		goal->completed = 1;
// 		return (malloc_operation("pb"));
// 	}
// 	value = ideal_nextb3(a, goal->goal);
// 	pos_value = get_position_from_value(a, value);
// 	pos_goal = get_position_from_value(a, goal->goal);
// 	dist = (pos_value - pos_goal) * (pos_value - pos_goal);
// 	if (stack_end(a)->value == ideal_nextb3(a, goal->goal) &&
// 		dist > 9)
// 	{
// 		goal->push_before_goal++;
// 		return (malloc_operation("pb"));
// 	}
// 	return goto_num(get_position_from_value(a, goal->goal), a);
// }

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

// char *closest_exit(t_stack *a, t_sorted_chain *sc)
// {
// 	if (stack_end(a)->number - sc->start - 1 > sc->end)
// 		return (malloc_operation("rra"));
// 	else
// 		return (malloc_operation("ra"));
// }

// char *inside_longest_chain(t_stack *a, t_sorted_chain *sc)
// {
// 	if (is_inside_longest_chain(stack_end(a)->value, a, sc) == 1)
// 		return closest_exit(a, sc);
// 	return 0;
// }
//
// char *away_longest_chain(t_stack *a, t_sorted_chain *sc)
// {
// 	if (sc == 0)
// 		return malloc_operation("rra");
// 	if (stack_end(a)->number - sc->end - 1 < sc->start)
// 		return (malloc_operation("rra"));
// 	else
// 		return (malloc_operation("ra"));
// }
// int			is_sortedb(t_stack *b)
// {
// 	if (b == 0)
// 		return (0);
// 	while (b->next != 0)
// 	{
// 		if (b->value > b->next->value)
// 			return (0);
// 		b = b->next;
// 	}
// 	return (1);
// }

// int			all_ordered(t_stack *a, t_stack *b)
// {
// 	if (b != 0)
// 		return (0);
// 	return (ordered(a));
// }

// int	sa_ideal(t_stack *s)
// {
// 	if (s == 0 || s->next == 0 || s->next->next == 0)
// 			return 0;
// 	printf("%i %i\n", stack_end(s)->value, ideal_next2(s, stack_end(s)->prev->value));
// 	if (stack_end(s)->value == ideal_next2(s, stack_end(s)->prev->value))
// 		return 0;
// 	printf("%i %i\n", stack_begin(s)->value, ideal_next2(s, stack_end(s)->value));
// 	if (stack_begin(s)->value == ideal_next2(s, stack_end(s)->value))
// 		return 0;
// 	printf("%i %i\n", stack_end(s)->prev->value, ideal_next2(s, stack_end(s)->prev->prev->value));
// 	if (ideal_next2(s, stack_end(s)->prev->prev->value) == stack_end(s)->prev->value)
// 		return 0;
// 	printf("%i %i\n", stack_end(s)->prev->value, ideal_next2(s, stack_end(s)->value));
// 	if (stack_end(s)->prev->value == ideal_next2(s, stack_end(s)->value))
// 		return (1);
// 	printf("%i %i\n", stack_begin(s)->value, ideal_next2(s, stack_end(s)->prev->value));
// 	fflush(stdout);
// 	if (ideal_next2(s, stack_end(s)->prev->value) == stack_begin(s)->value)
// 		return (1);
// 	return (0);
// }

// int	sa_ideal2(t_stack *s, t_sorted_chain *sc)
// {
// 	if (s == 0 || s->next == 0 || s->next->next == 0)
// 		return 0;
// 	if (sc == 0)
// 		return sa_ideal(s);
// 	if (stack_end(s)->prev->value == ideal_next2(s, stack_end(s)->value) && stack_end(s)->prev->value == sc->end)
// 		return (1);
// 	if (ideal_next2(s, stack_end(s)->prev->value) == stack_begin(s)->value && stack_begin(s)->value == sc->start)
// 		return (1);
// 	return (0);
// }


// char		*top_greater_than_second(t_stack *a, t_stack *b)
// {
// 	if (stack_end(a)->value < stack_end(a)->prev->value)
// 		return (0);
// 	if (sa_ideal(a))
// 		return (malloc_operation("sa"));
// 	else if (ideal_next(stack_end(a)) != stack_next(stack_end(a))->value)
// 		return (malloc_operation("pb"));
// 	else
// 		return out_longest_chain(a, b, longest_chain(a));
// }

// t_goal *init_goal()
// {
//   t_goal *goal;
//
//   if ((goal = malloc(sizeof(t_goal))) == 0)
//     ft_error("Malloc2 failed");
//   goal->todos_after_goal = 0;
//   goal->push_before_goal = 0;
//   goal->completed = 1;
//   return goal;
// }

// t_goal *set_new_goal(t_goal *goal, int g)
// {
//   goal->todos_after_goal = 0;
//   goal->completed = 0;
//   goal->push_before_goal = 0;
//   goal->goal = g;
//   return goal;
// }
//
// static t_goal *cut_todo(t_goal *goal, int cut)
// {
//   goal->todos_after_goal = ft_cut_f(goal->todos_after_goal, cut);
//   if (goal->todos_after_goal == 0)
//   {
//     free(goal->todos_after_goal);
//     goal->todos_after_goal = 0;
//   }
//   return goal;
// }
//
// char *get_todo(t_goal *goal)
// {
//   int i;
//   char *ret;
//
//   i = 0;
//   while (goal->todos_after_goal[i] != ' ')
//     i++;
//   if ((ret = ft_substr(goal->todos_after_goal, 0, i)) == 0)
//     ft_error("Malloc4 failed");
//   goal = cut_todo(goal, i + 1);
//   return ret;
// }
//
// static t_goal *add_todo(t_goal *goal, char *todo)
// {
//   if ((goal->todos_after_goal = ft_strjoin_f(goal->todos_after_goal, todo)) == 0)
//     ft_error("Malloc5 failed");
//   return goal;
// }
//
// t_goal *generate_todos(t_goal *goal)
// {
//   int i;
//
//   i = 0;
//   while (i != goal->push_before_goal)
//   {
//     if (i == 0)
//       goal = add_todo(goal, "sb ");
//     else
//       goal = add_todo(goal, "rb sb ");
//     i++;
//   }
//   while (goal->push_before_goal > 1)
//   {
//     goal = add_todo(goal, "rrb ");
//     goal->push_before_goal--;
//   }
//   goal->push_before_goal = 0;
//   return goal;
// }

// static void				chain(t_stack *a, t_sorted_chain *sc)
// {
// 	int no;
//
// 	no = 0;
// 	if (ordered(a))
// 	{
// 		sc->len = stack_end(a)->number;
// 		return ;
// 	}
// 	sc->start = a->number;
// 	while (ideal_next(a) == stack_next(a)->value)
// 	{
// 		no = 1;
// 		a = stack_next(a);
// 		if (a->number == sc->start)
// 			break ;
// 	}
// 	sc->end = a->number;
// 	if (sc->end > sc->start || no == 0)
// 		sc->len = sc->end - sc->start;
// 	else
// 		sc->len = sc->end + stack_end(a)->number + 1 - sc->start;
// }
//
// static t_sorted_chain	*get_chains(t_stack *a)
// {
// 	t_sorted_chain *sc;
//
// 	if ((sc = malloc(sizeof(t_sorted_chain))) == 0)
// 		ft_error("Malloc failed");
// 	sc->head = sc;
// 	sc->next = 0;
// 	while (a != 0)
// 	{
// 		chain(a, sc);
// 		if (sc->len == stack_end(a)->number)
// 		{
// 			free_sorted_chain(sc->head);
// 			return (0);
// 		}
// 		if ((sc->next = malloc(sizeof(t_sorted_chain))) == 0)
// 			ft_error("Malloc failed");
// 		sc->next->head = sc->head;
// 		sc = sc->next;
// 		sc->next = 0;
// 		a = a->next;
// 	}
// 	return (sc);
// }
//
// static t_sorted_chain	*find_longest_chain(t_sorted_chain *sc)
// {
// 	int longest;
//
// 	longest = -1;
// 	while (sc->next != 0)
// 	{
// 		if (sc->len > longest)
// 			longest = sc->len;
// 		// printf("%i\n", sc->len);
// 		// fflush(stdout);
// 		sc = sc->next;
// 	}
// 	if (sc->len > longest)
// 		longest = sc->len;
// 	sc = sc->head;
// 	while (sc->len != longest)
// 		sc = sc->next;
// 	if (sc->len == 0)
// 		return 0;
// 	return (sc);
// }
//
// t_sorted_chain	*longest_chain(t_stack *a)
// {
// 	t_sorted_chain *sc;
//
// 	if ((sc = get_chains(a)) == 0)
// 		return (0);
// 	return find_longest_chain(sc->head);
// }
// int	ideal_nextb2(t_stack *a, t_stack *b)
// {
// 	t_stack	*i;
// 	int		ideal;
// 	int value;
//
// 	i = stack_begin(a);
// 	if (b == 0)
// 		return get_value_from_position(a, smallest_value_num(a));
// 	value = stack_end(b)->value;
// 	ideal = value;
// 	while (i != 0)
// 	{
// 		if (value - i->value < 0 && (i->value < ideal || ideal == value))
// 			ideal = i->value;
// 		i = i->next;
// 	}
// 	if (ideal == value)
// 		return get_value_from_position(a, smallest_value_num(a));
// 	return (ideal);
// }

// int	ideal_nextb3(t_stack *a, int value)
// {
// 	t_stack	*i;
// 	int		ideal;
//
// 	i = stack_begin(a);
// 	ideal = value;
// 	while (i != 0)
// 	{
// 		if (value - i->value < 0 && (i->value < ideal || ideal == value))
// 			ideal = i->value;
// 		i = i->next;
// 	}
// 	// if (ideal == value)
// 	// 	return get_value_from_position(a, smallest_value_num(a));
// 	return (ideal);
// }

// char		*top_greater_than_second2(t_stack *a)
// {
// 	// t_sorted_chain *sc;
//
// 	if (stack_end(a)->value < stack_end(a)->prev->value)
// 		return (0);
// 	// sc = longest_chain(a);
// 	// if (sc == 0)
// 	// 	return (malloc_operation("sa"));
// 	// if (sc->end == stack_end(a)->prev->number || sc->start == stack_end(a)->number)
// 	// 	return out_longest_chain(a, 0, sc);
// 	return (malloc_operation("sa"));
// }

// int is_inside_longest_chain(int value, t_stack *a, t_sorted_chain *sc)
// {
// 	if (sc == 0)
// 		return (2);
// 	// printf("ILC: %i %i %i %i %i\n", value, sc->start, get_value_from_position(a, sc->start), sc->end, get_value_from_position(a, sc->end));
// 	// fflush(stdout);
// 	if (value <= get_value_from_position(a, sc->start) && value >= get_value_from_position(a, sc->end))
// 		return (1);
// 	if (value >= get_value_from_position(a, sc->start) && get_value_from_position(a, sc->start) <= get_value_from_position(a, sc->end) && value >= get_value_from_position(a, sc->end))
// 		return (1);
// 	if (value <= get_value_from_position(a, sc->start) && get_value_from_position(a, sc->start) <= get_value_from_position(a, sc->end))
// 		return (1);
// 	return (0);
// }

// int		smallest_value_outside_longest_chain_num(t_stack *s, t_sorted_chain *sc)
// {
// 	int small;
// 	int num;
//
// 	small = 2147483647;
// 	num = 2147483647;
// 	while (s != 0)
// 	{
// 		// printf("sm: %i %i\n", s->value, is_inside_longest_chain(s->value, s, sc));
// 		// fflush(stdout);
// 		if (s->value < small && (is_inside_longest_chain(s->value, s, sc) != 1))
// 		{
// 			small = s->value;
// 			num = s->number;
// 		}
// 		s = s->next;
// 	}
// 	// write(1, "1", 1);
// 	return (num);
// }
// int	ideal_nextb(t_stack *a, t_stack *b, t_sorted_chain *sc)
// {
// 	t_stack	*i;
// 	int		ideal;
// 	int value;
//
// 	i = stack_begin(a);
// 	if (b == 0)
// 		return get_value_from_position(a, smallest_value_outside_longest_chain_num(a, sc));
// 	value = stack_end(b)->value;
// 	ideal = value;
// 	while (i != 0)
// 	{
// 		if (value - i->value < 0 && (i->value < ideal || ideal == value) && !is_inside_longest_chain(i->value, a, sc))
// 			ideal = i->value;
// 		i = i->next;
// 	}
// 	if (ideal == value)
// 		return get_value_from_position(a, smallest_value_outside_longest_chain_num(a, sc));
// 	return (ideal);
// }

/*
**If no ideal next because is smallest value -> returns itself
**which cannot be equal to another number as all are unique
*/

// int	ideal_next(t_stack *a)
// {
// 	t_stack	*i;
// 	int		ideal;
//
// 	i = stack_begin(a);
// 	ideal = a->value;
// 	while (i != 0)
// 	{
// 		if (a->value - i->value > 0 && (i->value > ideal || ideal == a->value))
// 			ideal = i->value;
// 		i = i->next;
// 	}
// 	if (ideal == a->value)
// 		return stack_biggest_value(a);
// 	return (ideal);
// }
//
// int	ideal_next2(t_stack *a, int value)
// {
// 	t_stack	*i;
// 	int		ideal;
//
// 	i = stack_begin(a);
// 	ideal = value;
// 	while (i != 0)
// 	{
// 		if (value - i->value > 0 && (i->value > ideal || ideal == value))
// 			ideal = i->value;
// 		i = i->next;
// 	}
// 	if (ideal == value)
// 		return stack_biggest_value(a);
// 	return (ideal);
// }

// int		get_value_from_position(t_stack *a, int pos)
// {
// 	a = stack_begin(a);
// 	while (a != 0)
// 	{
// 		if (a->number == pos)
// 			return (a->value);
// 		a = a->next;
// 	}
// 	// printf("pos:%i\n", pos);
// 	// fflush(stdout);
// 	ft_error("get_value_from_pos function error");
// 	return (0);
// }

// int		get_position_from_value(t_stack *a, int value)
// {
// 	while (a != 0)
// 	{
// 		if (a->value == value)
// 			return (a->number);
// 		a = a->next;
// 	}
// 	ft_error("get_position_from_value function error");
// 	return (0);
// }

// void	free_sorted_chain(t_sorted_chain *sc)
// {
// 	t_sorted_chain *rem;
//
// 	while (sc != 0)
// 	{
// 		rem = sc;
// 		sc = sc->next;
// 		free(rem);
// 	}
// }
// typedef struct	s_sorted_chain
// {
// 	int						start;
// 	int						end;
// 	int						len;
// 	struct s_sorted_chain	*next;
// 	struct s_sorted_chain	*head;
// }				t_sorted_chain;
