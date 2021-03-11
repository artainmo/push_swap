#include "push_swap.h"

t_ab_stack *find_operation(t_ab_stack *s, char *line)
{
  if (ft_strcmp(line, "sa"))
  {
    s->a = ft_s(s->a);
    return s;
  }
  else if (ft_strcmp(line, "sb"))
  {
    s->b = ft_s(s->b);
    return s;
  }
  else if (ft_strcmp(line, "ss"))
  {
    s->a = ft_s(s->a);
    s->b = ft_s(s->b);
    return s;
  }
  else if (ft_strcmp(line, "pa"))
  {
    s = ft_pa(s);
    return s;
  }
  else if (ft_strcmp(line, "pb"))
  {
    s = ft_pb(s);
    return s;
  }
  else if (ft_strcmp(line, "ra"))
  {
    s->a = ft_r(s->a);
    return s;
  }
  else if (ft_strcmp(line, "rb"))
  {
    s->b = ft_r(s->b);
    return s;
  }
  else if (ft_strcmp(line, "rr"))
  {
    s->a = ft_r(s->a);
    s->b = ft_r(s->b);
    return s;
  }
  else if (ft_strcmp(line, "rra"))
  {
    s->a = ft_rr(s->a);
    return s;
  }
  else if (ft_strcmp(line, "rrb"))
  {
    s->b = ft_rr(s->b);
    return s;
  }
  else if (ft_strcmp(line, "rrr"))
  {
    s->a = ft_rr(s->a);
    s->b = ft_rr(s->b);
    return s;
  }
  else
    ft_error("Error");
  return s;
}


int is_sorted(t_stack *a, t_stack *b)
{
  if (b != 0)
    return 0;
  while (a->next != 0)
  {
    if (a->value < a->next->value)
      return 0;
    a = a->next;
  }
  return 1;
}

void verify_duplicates2(int value, t_stack *s)
{
  t_stack *loop;

  loop = s;
  while (loop != 0)
  {
    if (loop->value == value)
      ft_error("Error");
    loop = loop->next;
  }
}

void verify_duplicates(t_stack *a)
{
  t_stack *loop;

  loop = a;
  while (loop != 0)
  {
    verify_duplicates2(loop->value, loop->next);
    loop = loop->next;
  }
}

void verify_number_errors(int argc, char **argv)
{
  while (argc > 1)
  {
    if (!ft_str_isdigit(argv[argc - 1]) || (!ft_atoi(argv[argc - 1]) && ft_strlen(argv[argc - 1]) != 1))
      ft_error("Error");
    argc--;
  }
}

//Live let you make changes and visualize them right after each operation
char **verify_bonuses(int *argc, char **argv, int *vis, int *color, int *live)
{
  int i;

  i = 1;
  while (i < 3 && i < *argc)
  {
    if (ft_strcmp(argv[i], "-v"))
      *vis = 1;
    if (ft_strcmp(argv[i], "-c"))
      *color = 1;
    if (i == 1 && ft_strcmp(argv[i], "-l"))
    {
      *live = 1;
      *argc = *argc - 1;
      return &argv[1];
    }
    i++;
  }
  if (*vis && *color)
  {
    *argc = *argc - 2;
    return &argv[2];
  }
  else if (*vis || *color)
  {
    *argc = *argc - 1;
    return &argv[1];
  }
  return &argv[0];
}


void show_operations(t_operations *o, int visual, int color)
{
  int i;
  char *str;

  i = 0;
  while (o->next != 0 && o->line != 0)
  {
    if (visual && o->next->next != 0)
      show_stack(o->s->a, o->s->b, o->line, 0);
    else if (visual && o->next->next == 0) //operations ends with empty oper
      show_stack(o->s->a, o->s->b, o->line, color);
    else
    {
      write(1, o->line, ft_strlen(o->line));
      write(1, "\n", 1);
    }
    o = o->next;
    i++;
  }
  if (visual)
  {
    if ((str = ft_itoa(i)) == 0)
      ft_error("Malloc failed");
    write(1, "Total steps: ", 13);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
  }
}

char *malloc_operation(char *operation)
{
  char *ret;

  if ((ret = ft_strdup(operation)) == 0)
    ft_error("Malloc failed");
  return ret;
}
