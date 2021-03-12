#include "../push_swap.h"


char *shortest_path_to_correct_placement(t_stack *a)
{
  // printf("%i %i\n", stack_end(a)->number - stack_highest_value_pos(a) + 1, stack_highest_value_pos(a));
  if (stack_end(a)->number - stack_highest_value_pos(a) + 1 < stack_highest_value_pos(a))
  {
    p("6");
    return malloc_operation("ra");
  }
  else
  {
    p("2");
    return malloc_operation("rra");
  }
}

//Only check if top stack can be inserted in ideal position relative to next value
char *b_values_ideal_position_a(t_stack *a, t_stack *b)
{
  if (b == 0)
    return 0;
  // printf("%i %i\n", a->value, ideal_next2(a, stack_end(b)->value));
  if (a->value == ideal_next2(a, stack_end(b)->value))
    return malloc_operation("pa");
  return 0;
}

static char *goto_ideal_value_top_b(t_stack *a, t_stack *b)
{
  int pos;

  pos = get_position_from_value(a, ideal_next2(a, stack_end(b)->value));
  // printf("%i %i\n", stack_end(b)->value, pos);
  // printf("%i %i\n", pos, stack_end(a)->number - pos + 1);
  if (pos <= stack_end(a)->number - pos + 1)
  {
      p("1");
      return malloc_operation("rra");
  }
  else
  {
      p("7");
      return malloc_operation("ra");
  }
}

char *top_smaller_than_second(t_stack *a, t_stack *b)
{
  int dir;

  if (stack_end(a)->value > stack_end(a)->prev->value)
    return 0;
  if ((dir = longest_chain_dir(a)) == -1 && b != 0)
    return goto_ideal_value_top_b(a, b);
  if (dir == 2)
  {
    p("3");
    return malloc_operation("rra");
  }
  else if (dir == 1)
  {
    p("8");
    return malloc_operation("ra");
  }
  else if (dir == -1)
  {
    p("4");
    return malloc_operation("rra");
  }
  p("5");
  return malloc_operation("ra"); //else if (dir == -2)
}

// int main()
// {
//   t_sorted_chain *sc;
//   t_stack *a;
//   t_stack *b;
//
//   if ((sc = malloc(sizeof(t_sorted_chain))) == 0)
//     ft_error("Malloc failed");
//   a = 0;
//   b = 0;
//   b = stack_push(b, 6);
//   b = stack_push(b, 10);
//   a = stack_push(a, 5);
//   a = stack_push(a, 3);
//   a = stack_push(a, 2);
//   a = stack_push(a, 1);
//   a = stack_push(a, 0);
//   show_stack(a, b, "Init", 0);
//
//   printf("FINAL: %s", top_smaller_than_second(a, b));
//
//   show_stack(a, b, "Init", 0);
// }
