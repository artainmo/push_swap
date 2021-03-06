/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ab_stack		*ab_stack_copy(t_ab_stack *s)
{
	t_ab_stack *ret;

	if ((ret = malloc(sizeof(t_ab_stack))) == 0)
		ft_error("Malloc9 failed");
	ret->a = stack_copy(s->a);
	ret->b = stack_copy(s->b);
	return (ret);
}

t_ab_stack		*init_ab_stack(t_stack *a, t_stack *b)
{
	t_ab_stack *s;

	if ((s = malloc(sizeof(t_ab_stack))) == 0)
		ft_error("Malloc10 failed");
	s->a = a;
	s->b = b;
	return (s);
}

t_operations	*init_operations(void)
{
	t_operations *o;

	if ((o = malloc(sizeof(t_operations))) == 0)
		ft_error("Malloc11 failed");
	o->head = o;
	o->next = 0;
	o->line = 0;
	o->s = 0;
	return (o);
}
