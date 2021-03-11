#include "push_swap.h"

t_stack *stack_init(int value)
{
  t_stack *new;

  if ((new = malloc(sizeof(t_stack))) == 0)
    ft_error("Malloc failed");
  new->next = 0;
  new->prev = 0;
  new->value = value;
  new->number = 0;
  return new;
}

t_stack *stack_end(t_stack *stack)
{
  if (stack == 0)
    return 0;
  while (stack->next != 0)
    stack = stack->next;
  return stack;
}

t_stack *stack_begin(t_stack *stack)
{
  if (stack == 0)
    return 0;
  while (stack->prev != 0)
    stack = stack->prev;
  return stack;
}

t_stack *stack_push(t_stack *stack, int value)
{
  if (stack == 0)
    return stack_init(value);
  else
  {
    stack = stack_end(stack);
    if ((stack->next = malloc(sizeof(t_stack))) == 0)
      ft_error("Malloc failed");
    stack->next->prev = stack;
    stack->next->next = 0;
    stack->next->value = value;
    stack->next->number = stack->number + 1;
  }
  return stack_begin(stack);
}

t_stack *stack_pop(t_stack *stack)
{
  if (stack == 0)
    ft_error("Trying to remove element from empty stack");
  stack = stack_end(stack);
  if (stack->prev == 0)
  {
    free(stack);
    return 0;
  }
  else
  {
    stack = stack->prev;
    free(stack->next);
    stack->next = 0;
    return stack_begin(stack);
  }
}
