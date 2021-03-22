/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_algo3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_goal *init_goal()
{
  t_goal *goal;

  if ((goal = malloc(sizeof(t_goal))) == 0)
    ft_error("Malloc2 failed");
  goal->todos_after_goal = 0;
  goal->push_before_goal = 0;
  goal->completed = 1;
  return goal;
}

t_goal *set_new_goal(t_goal *goal, int g)
{
  goal->todos_after_goal = 0;
  goal->completed = 0;
  goal->push_before_goal = 0;
  goal->goal = g;
  return goal;
}

static t_goal *cut_todo(t_goal *goal, int cut)
{
  goal->todos_after_goal = ft_cut_f(goal->todos_after_goal, cut);
  if (goal->todos_after_goal == 0)
  {
    free(goal->todos_after_goal);
    goal->todos_after_goal = 0;
  }
  return goal;
}

char *get_todo(t_goal *goal)
{
  int i;
  char *ret;

  i = 0;
  while (goal->todos_after_goal[i] != ' ')
    i++;
  if ((ret = ft_substr(goal->todos_after_goal, 0, i)) == 0)
    ft_error("Malloc4 failed");
  goal = cut_todo(goal, i + 1);
  return ret;
}

static t_goal *add_todo(t_goal *goal, char *todo)
{
  if ((goal->todos_after_goal = ft_strjoin_f(goal->todos_after_goal, todo)) == 0)
    ft_error("Malloc5 failed");
  return goal;
}

t_goal *generate_todos(t_goal *goal)
{
  int i;

  i = 0;
  while (i != goal->push_before_goal)
  {
    if (i == 0)
      goal = add_todo(goal, "sb ");
    else
      goal = add_todo(goal, "rb sb ");
    i++;
  }
  while (goal->push_before_goal > 1)
  {
    goal = add_todo(goal, "rrb ");
    goal->push_before_goal--;
  }
  goal->push_before_goal = 0;
  return goal;
}

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
