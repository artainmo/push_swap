#include "../push_swap.h"

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

static t_sorted_chain *get_chains(t_stack *a, t_sorted_chain *sc)
{
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
  return sc;
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

int longest_chain_dir_return(t_stack *a, t_sorted_chain *sc)
{
  if (sc->start > sc->end || stack_end(a)->number == sc->end) //It is in
  {
    if (stack_end(a)->number - sc->start - 1 > sc->end) //It is down
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
  if (stack_end(a)->number - sc->end - 1 < sc->start) //It is down
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

//Returns 1 if longest chain is closer up (oposite direction -> rr) and 2 if it is closer down (oposite direction -> r) based on upper value relative to performed view by show_stack
//If longest chain exit is closer down return -1 (same direction -> rr) and if it is closer up return -2 (same direction -> r)
//Returns 0 if all is ordered then value closest to b value must be moved to
int longest_chain_dir(t_stack *a)
{
  t_sorted_chain *sc;

  if ((sc = malloc(sizeof(t_sorted_chain))) == 0)
    ft_error("Malloc failed");
  sc->head = sc;
  if ((sc = get_chains(a, sc)) == 0)
    return 0;
  sc = find_longest_chain(sc->head);
  return longest_chain_dir_return(a, sc);

}
