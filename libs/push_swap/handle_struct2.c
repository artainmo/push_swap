#include "push_swap.h"

void show_stack(t_stack *a, t_stack *b, char *title, int color)
{
  char *first;

  if (color == 1)
    write(1, "\033[0;36m", 8);
  write(1, "-------------------\n", 20);
  write(1, title, ft_strlen(title));
  write(1, "\n", 1);
  write(1, "stack a     stack b\n", 20);
  a = stack_end(a);
  b = stack_end(b);
  while (a != 0 || b != 0)
  {
    first = "";
    if (a != 0)
    {
      first = ft_itoa(a->value);
      write(1, first, ft_strlen(first));
      a = a->prev;
    }
    write(1, "            ", 12 - ft_strlen(first));
    if (b != 0)
    {
      write(1, ft_itoa(b->value), ft_strlen(ft_itoa(b->value)));
      b = b->prev;
    }
    write(1, "\n", 1);
  }
  write(1, "-------------------\n", 20);
  write(1, "\033[0;37m", 8);
}

void free_stack(t_stack *s)
{
  t_stack *rem;

  while (s != 0)
  {
    rem = s;
    s = s->next;
    free(rem);
  }
}

void free_ab_stack(t_ab_stack *s)
{
  free_stack(s->a);
  free_stack(s->b);
  free(s);
}

void free_operations(t_operations *o)
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
    free(rem);
  }
}

void free_sorted_chain(t_sorted_chain *sc)
{
  t_sorted_chain *rem;

  while (sc != 0)
  {
    rem = sc;
    sc = sc->next;
    free(rem);
  }
}
