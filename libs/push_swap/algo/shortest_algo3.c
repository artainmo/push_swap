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

static void				chain(t_stack *a, t_sorted_chain *sc)
{
	int no;

	no = 0;
	if (ordered(a))
	{
		sc->len = stack_end(a)->number;
		return ;
	}
	sc->start = a->number;
	while (ideal_next(a) == stack_next(a)->value)
	{
		no = 1;
		a = stack_next(a);
		if (a->number == sc->start)
			break ;
	}
	sc->end = a->number;
	if (sc->end > sc->start || no == 0)
		sc->len = sc->end - sc->start;
	else
		sc->len = sc->end + stack_end(a)->number + 1 - sc->start;
}

static t_sorted_chain	*get_chains(t_stack *a)
{
	t_sorted_chain *sc;

	if ((sc = malloc(sizeof(t_sorted_chain))) == 0)
		ft_error("Malloc failed");
	sc->head = sc;
	while (a != 0)
	{
		chain(a, sc);
		if (sc->len == stack_end(a)->number)
		{
			free_sorted_chain(sc->head);
			return (0);
		}
		if ((sc->next = malloc(sizeof(t_sorted_chain))) == 0)
			ft_error("Malloc failed");
		sc->next->head = sc->head;
		sc = sc->next;
		a = a->next;
	}
	return (sc);
}

static t_sorted_chain	*find_longest_chain(t_sorted_chain *sc)
{
	int longest;

	longest = -1;
	while (sc->next != 0)
	{
		if (sc->len > longest)
			longest = sc->len;
		// printf("%i\n", sc->len);
		// fflush(stdout);
		sc = sc->next;
	}
	if (sc->len > longest)
		longest = sc->len;
	sc = sc->head;
	while (sc->len != longest)
		sc = sc->next;
	if (sc->len == 0)
		return 0;
	return (sc);
}

t_sorted_chain	*longest_chain(t_stack *a)
{
	t_sorted_chain *sc;

	if ((sc = get_chains(a)) == 0)
		return (0);
	return find_longest_chain(sc->head);
}
