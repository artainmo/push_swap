#include "push_swap.h"

int stack_last_value(t_stack *s)
{
  return stack_end(s)->value;
}

int stack_second_last_value(t_stack *s)
{
  return stack_end(s)->prev->value;
}

int stack_first_value(t_stack *s)
{
  return stack_begin(s)->value;
}

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

//If no ideal next because is smallest value -> returns itself
//, which cannot be equal to another number as all are unique
int ideal_next(t_stack *a)
{
  t_stack *i;
  int ideal;

  i = stack_begin(a);
  ideal = a->value;
  while (i != 0)
  {
    if (a->value - i->value > 0 && (i->value > ideal || ideal == a->value))
      ideal = i->value;
    i = i->next;
  }
  return ideal;
}

int ideal_next2(t_stack *a, int value)
{
  t_stack *i;
  int ideal;

  i = stack_begin(a);
  ideal = value;
  while (i != 0)
  {
    if (value - i->value > 0 && (i->value > ideal || ideal == value))
      ideal = i->value;
    i = i->next;
  }
  return ideal;
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

t_ab_stack *ab_stack_copy(t_ab_stack *s)
{
  t_ab_stack *ret;

  if ((ret = malloc(sizeof(t_ab_stack))) == 0)
    ft_error("Malloc failed");
  ret->a = stack_copy(s->a);
  ret->b = stack_copy(s->b);
  return ret;
}
