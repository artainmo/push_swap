/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_init(int value, int partition)
{
	t_stack *new;

	if ((new = malloc(sizeof(t_stack))) == 0)
		ft_error("Malloc7 failed");
	new->next = 0;
	new->prev = 0;
	new->value = value;
	new->number = 0;
	new->partition = partition;
	return (new);
}

t_stack	*stack_end(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_begin(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->prev != 0)
		stack = stack->prev;
	return (stack);
}

t_stack	*stack_push(t_stack *stack, int value, int partition)
{
	if (stack == 0)
		return (stack_init(value, partition));
	else
	{
		stack = stack_end(stack);
		if ((stack->next = malloc(sizeof(t_stack))) == 0)
			ft_error("Malloc8 failed");
		stack->next->prev = stack;
		stack->next->next = 0;
		stack->next->value = value;
		stack->next->number = stack->number + 1;
		stack->next->partition = partition;
	}
	return (stack_begin(stack));
}

t_stack	*stack_pop(t_stack *stack)
{
	if (stack == 0)
		ft_error("Trying to remove element from empty stack");
	stack = stack_end(stack);
	if (stack->prev == 0)
	{
		free(stack);
		return (0);
	}
	else
	{
		stack = stack->prev;
		free(stack->next);
		stack->next = 0;
		return (stack_begin(stack));
	}
}
