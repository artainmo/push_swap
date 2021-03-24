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
	while (stack->next != 0 && stack->partition != partition + 1)
		stack = stack->next;
	if (stack->partition == partition + 1)
		return (stack->prev);
	return (stack);
}

t_stack *partition_begin(t_stack *stack, int partition)
{
	if (stack == 0)
		return (0);
	while (stack->next != 0 && stack->partition != partition)
		stack = stack->next;
	if (stack->partition != partition)
		ft_error("partition begin error");
	return (stack);
}

t_stack	*stack_position(t_stack *s, int number)
{
	while (s->number != number)
		s = s->next;
	return (s);
}

int stack_biggest_value(t_stack *a)
{
	t_stack	*i;
	int		biggest;

	i = stack_begin(a);
	biggest = i->value;
	while (i != 0)
	{
		if (biggest < i->value)
			biggest = i->value;
		i = i->next;
	}
	return biggest;
}

int		stack_highest_value_pos(t_stack *s)
{
	int big;
	int num;

	big = -2147483648;
	num = -2147483648;
  s = stack_begin(s);
	while (s != 0)
	{
		if (s->value > big)
		{
			big = s->value;
			num = s->number;
		}
		s = s->next;
	}
	return (num);
}

int		stack_lowest_value_pos(t_stack *s)
{
	int small;
	int num;

	small = 2147483647;
	num = 2147483647;
  s = stack_begin(s);
	while (s != 0)
	{
		if (s->value < small)
		{
			small = s->value;
			num = s->number;
		}
		s = s->next;
	}
	return (num);
}

t_stack	*stack_next(t_stack *s)
{
	if (s->next == 0)
		return (stack_begin(s));
	else
		return (s->next);
}

int		get_position_from_value(t_stack *a, int value)
{
	while (a != 0)
	{
		if (a->value == value)
			return (a->number);
		a = a->next;
	}
	ft_error("get_position_from_value function error");
	return (0);
}

int		get_value_from_position(t_stack *a, int pos)
{
	a = stack_begin(a);
	while (a != 0)
	{
		if (a->number == pos)
			return (a->value);
		a = a->next;
	}
	// printf("pos:%i\n", pos);
	// fflush(stdout);
	ft_error("get_value_from_pos function error");
	return (0);
}

t_stack	*stack_copy(t_stack *a)
{
	t_stack *cpy;

	cpy = 0;
	while (a != 0)
	{
		cpy = stack_push(cpy, a->value, a->partition);
		a = a->next;
	}
	return (cpy);
}
