/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_len(t_stack *stack)
{
  int i;

  i = 0;
  if (stack == 0)
		return (0);
	while (stack != 0)
  {
    i++;
		stack = stack->next;
  }
  return (i);
}

t_stack *partition_end(t_stack *stack, int partition)
{
	if (stack == 0)
		return (0);
  stack = stack_end(stack);
	while (stack->prev != 0 && stack->partition != partition)
		stack = stack->prev;
	return (stack);
}

t_stack *partition_begin(t_stack *stack, int partition)
{
	if (stack == 0)
		return (0);
  stack = stack_end(stack);
	while (stack->prev != 0 && stack->partition != partition - 1)
		stack = stack->prev;
	if (stack->partition == partition - 1)
    stack = stack->next;
	return (stack);
}

t_stack	*stack_position(t_stack *s, int number)
{
	while (s->number != number)
		s = s->next;
	return (s);
}
