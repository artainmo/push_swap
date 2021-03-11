#include "push_swap.h"

static int ordered(t_stack *a)
{
  int start;

  a = stack_position(a, stack_highest_value_pos(a));
  start = a->number;
  while (a->value > stack_next(a)->value)
  {
    a = stack_next(a);
    if (stack_next(a)->number == start)
      return 1;
  }
  return 0;
}

int all_ordered(t_stack *a, t_stack *b)
{
  if (b != 0)
    return 0;
  return ordered(a);
}

static void chain(t_stack *a, t_sorted_chain *sc)
{
  int no;

  no = 0;
  if (ordered(a))
  {
    sc->len = stack_end(a)->number;
    return ;
  }
  sc->start = a->number;
  // printf("%i %i\n", ideal_next(a), stack_next(a)->value);
  // fflush(stdout);
  while (ideal_next(a) == stack_next(a)->value)
  {
    no = 1;
    a = stack_next(a);
    if (a->number == sc->start)
      break ;
  }
  sc->end = a->number;
  if (sc->end > sc->start || no == 0)
    sc->len = sc->end - sc->start;
  else
    sc->len = sc->end + stack_end(a)->number + 1 - sc->start;
}

static t_sorted_chain *find_longest_chain(t_sorted_chain *sc)
{
  int longest;

  longest = -1;
  while (sc->next != 0)
  {
    if (sc->len > longest)
      longest = sc->len;
    sc = sc->next;
  }
  if (sc->len > longest)
    longest = sc->len;
  sc = sc->head;
  while (sc->len != longest)
    sc = sc->next;
  return sc;
}

//Returns 1 if longest chain is closer up (oposite direction -> rr) and 2 if it is closer down (oposite direction -> r) based on upper value relative to performed view by show_stack
//If longest chain exit is closer down return -1 (same direction -> rr) and if it is closer up return -2 (same direction -> r)
//Returns 0 if all is ordered then value closest to b value must be moved to
int longest_chain_dir(t_stack *a)
{
  t_sorted_chain *sc;
  t_stack *i;

  if ((sc = malloc(sizeof(t_sorted_chain))) == 0)
    ft_error("Malloc failed");
  sc->head = sc;
  i = a;
  while (a != 0)
  {
    chain(a, sc);
    // printf("%i %i %i\n", sc->start, sc->end, sc->len);
    // // printf("%i\n", stack_end(a)->number);
    if (sc->len == stack_end(a)->number)
    {
      free_sorted_chain(sc->head);
      return 0;
    }
    if ((sc->next = malloc(sizeof(t_sorted_chain))) == 0)
      ft_error("Malloc failed");
    sc->next->head = sc->head;
    sc = sc->next;
    a = a->next;
  }
  sc = find_longest_chain(sc->head);
  if (sc->start > sc->end || stack_end(i)->number == sc->end) //It is in
  {
    if (stack_end(i)->number - sc->start - 1 > sc->end) //It is down
    {
      free_sorted_chain(sc->head);
      return -1;
    }
    else //It is up
    {
      free_sorted_chain(sc->head);
      return -2;
    }
  }
  // printf("%i < %i\n", stack_end(i)->number - sc->end - 1, sc->start);
  // fflush(stdout);
  if (stack_end(i)->number - sc->end - 1 < sc->start) //It is down
  {
    free_sorted_chain(sc->head);
    return 2;
  }
  else //It is up
  {
    free_sorted_chain(sc->head);
    return 1;
  }
}

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

char *top_smaller_than_second(t_stack *a, t_stack *b)
{
  int dir;
  int pos;

  if (stack_end(a)->value > stack_end(a)->prev->value)
    return 0;
  if ((dir = longest_chain_dir(a)) == -1 && b != 0)
  {
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

static int sa_ideal(t_stack *a)
{
  t_stack *cpy;
  int ret;

  cpy = stack_copy(a);
  cpy = ft_s(cpy);
  ret = ordered(cpy);
  free_stack(cpy);
  return ret;
}


char *top_greater_than_second(t_stack *a)
{
  if (stack_end(a)->value < stack_end(a)->prev->value)
    return 0;
  if (sa_ideal(a))
    return malloc_operation("sa");
  else
    return malloc_operation("pb");
}
