#include "../push_swap.h"


t_stack *stack_position(t_stack *s, int number)
{
  while (s->number != number)
    s = s->next;
  return s;
}

int stack_highest_value_pos(t_stack *s)
{
  int big;
  int num;

  big = -2147483648;
  while (s != 0)
  {
    if (s->value > big)
    {
      big = s->value;
      num = s->number;
    }
    s = s->next;
  }
  return num;
}

t_stack *stack_next(t_stack *s)
{
  if (s->next == 0)
    return stack_begin(s);
  else
    return s->next;
}

int get_position_from_value(t_stack *a, int value)
{
  while (a != 0)
  {
    if (a->value == value)
      return a->number;
    a = a->next;
  }
  ft_error("get_position_from_value function error");
  return 0;
}

t_stack *stack_copy(t_stack *a)
{
  t_stack *cpy;

  cpy = 0;
  while (a != 0)
  {
    cpy = stack_push(cpy, a->value);
    a = a->next;
  }
  return cpy;
}
