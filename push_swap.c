#include "push_swap.h"

//Ideal place refers to one of two moved values ideally placed relative to front or back value
//Maybe follow two paths one with ra as base direction and another with rra as base direction
static void shortest_operation(t_ab_stack *s, t_operations *o)
{
  char *ret;

  if (all_ordered(s->a, s->b))
    o->line = shortest_path_to_correct_placement(s->a);
  else if ((ret = b_values_ideal_position_a(s->a, s->b)) != 0)
    o->line = ret;
  else if ((ret = top_smaller_than_second(s->a, s->b)) != 0)
    o->line = ret;
  else if ((ret = top_greater_than_second(s->a)) != 0)
    o->line = ret;
  else
    ft_error("Error: no operation found");
}

static t_operations *get_operations(t_stack *a, t_stack *b)
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
  o->next = 0;
  o->line = 0;
  while (!is_sorted(s->a, s->b))
  {
    shortest_operation(s, o);
    s = find_operation(s, o->line);
    // show_stack(s->a, s->b, o->line, 0);
    o->s = ab_stack_copy(s);
    if ((o->next = malloc(sizeof(t_operations))) == 0)
      ft_error("Malloc failed");
    o->next->head = o->head;
    o = o->next;
    o->next = 0;
  }
  free_ab_stack(s);
  return (o);
}

int main(int argc, char **argv)
{
  t_ab_stack *s;
  t_operations *o;
  int visual;
  int color;

  if ((s = malloc(sizeof(t_ab_stack))) == 0)
    ft_error("Malloc failed");
  s->a = 0;
  s->b = 0;
  visual = 0;
  color = 0;
  argv = verify_bonuses(&argc, argv, &visual, &color, 0);
  if (argc == 1)
    exit(1);
  verify_number_errors(argc, argv);
  while (argc > 1)
  {
    s->a = stack_push(s->a, ft_atoi(argv[argc - 1]));
    argc--;
  }
  verify_duplicates(s->a);
  if (visual)
    show_stack(s->a, s->b, "Init", 0);
  o = get_operations(s->a, s->b);
  show_operations(o->head, visual, color);
  free_operations(o->head);
  return 0;
}

// int main()
// {
//   return 0;
// }
