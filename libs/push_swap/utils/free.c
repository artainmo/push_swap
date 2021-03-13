/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *s)
{
	t_stack *rem;

	while (s != 0)
	{
		rem = s;
		s = s->next;
		free(rem);
	}
}

void	free_ab_stack(t_ab_stack *s)
{
	free_stack(s->a);
	free_stack(s->b);
	free(s);
}

void	free_operations(t_operations *o)
{
	t_operations *rem;

	while (o != 0)
	{
		rem = o;
		o = o->next;
		if (rem->line != 0 && rem->s != 0)
		{
			free(rem->s->a);
			free(rem->s->b);
			free(rem->s);
		}
		free(rem->line);
		free(rem);
	}
}

void	free_sorted_chain(t_sorted_chain *sc)
{
	t_sorted_chain *rem;

	while (sc != 0)
	{
		rem = sc;
		sc = sc->next;
		free(rem);
	}
}
