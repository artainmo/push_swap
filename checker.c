#include "push_swap.h"


static void do_it_live(t_stack *a, t_stack *b)
{
  t_ab_stack *s;
  char *line;

  if ((s = malloc(sizeof(t_ab_stack))) == 0)
    ft_error("Malloc failed");
  s->a = a;
  s->b = b;
  show_stack(s->a, s->b, "Init:", 0);
  while (1)
  {
    if ((get_next_line(0, &line)) == -1)
			ft_error("get_next_line error");
    if (ft_strlen(line) == 0)
      break ;
    s = find_operation(s, line);
    show_stack(s->a, s->b, line, 0);
  }
  if (is_sorted(s->a, s->b))
    write(1, "OK\n", 3);
  else
    write(1, "KO\n", 3);
  free_stack(s->a);
  free_stack(s->b);
  free(s);
}



static void take_input(t_stack *a, t_stack *b, int visual, int color)
{
  t_operations *o;
  t_ab_stack *s;

  if ((s = malloc(sizeof(t_ab_stack))) == 0)
    ft_error("Malloc failed");
  s->a = a;
  s->b = b;
  if ((o = malloc(sizeof(t_operations))) == 0)
    ft_error("Malloc failed");
  o->head = o;
  o->s = 0;
  while (1)
  {
    if ((get_next_line(0, &o->line)) == -1)
			ft_error("get_next_line error");
    if (ft_strlen(o->line) == 0)
    {
      o->next = 0;
      o = o->head;
      break ;
    }
    if ((o->next = malloc(sizeof(t_operations))) == 0)
      ft_error("Malloc failed");
    o->next->head = o->head;
    o = o->next;
    o->next = 0;
    o->s = 0;
  }
  o = o->head;
  while (o->next != 0)
  {
    s = find_operation(s, o->line);
    if (visual && color && o->next->next == 0)
      show_stack(s->a, s->b, o->line, 1);
    else if (visual)
      show_stack(s->a, s->b, o->line, 0);
    o = o->next;
  }
  free_operations(o->head);
  if (is_sorted(s->a, s->b))
    write(1, "OK\n", 3);
  else
    write(1, "KO\n", 3);
  free_stack(s->a);
  free_stack(s->b);
  free(s);
}

int main(int argc, char **argv)
{
  t_stack *a;
  t_stack *b;
  int visual;
  int color;
  int live;

  a = 0;
  b = 0;
  visual = 0;
  color = 0;
  live = 0;
  argv = verify_bonuses(&argc, argv, &visual, &color, &live);
  if (argc == 1)
    exit(1);
  verify_number_errors(argc, argv);
  while (argc > 1)
  {
    a = stack_push(a, ft_atoi(argv[argc - 1]));
    argc--;
  }
  // printf("END:%i\n", stack_end(a)->value);
  // fflush(stdout);
  // printf("BEGIN:%i\n", stack_begin(a)->value);
  // fflush(stdout);
  verify_duplicates(a);
  if (visual)
    show_stack(a, b, "Init", 0);
  if (!live)
    take_input(a, b, visual, color);
  else
    do_it_live(a, b);
  return 0;
}
