/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


static void do_it_live(t_ab_stack *s)
{
  char *line;

  show_stack(s->a, s->b, "Init:", 1, 0);
  while (1)
  {
    if ((get_next_line(0, &line)) == -1)
			ft_error("get_next_line error");
    if (ft_strlen(line) == 0)
      break ;
    s = find_operation(s, line);
    show_stack(s->a, s->b, line, 1, 0);
  }
  if (is_sorted(s->a, s->b))
    write(1, "OK\n", 3);
  else
    write(1, "KO\n", 3);
  free_ab_stack(s);
}

static void apply_input(t_operations *o, t_ab_stack *s, int visual, int color)
{
  while (o->next != 0)
  {
    s = find_operation(s, o->line);
    if (visual && color && o->next->next == 0)
      show_stack(s->a, s->b, o->line, 1, 1);
    else if (visual)
      show_stack(s->a, s->b, o->line, 1, 0);
    o = o->next;
  }
  if (is_sorted(s->a, s->b))
    write(1, "OK\n", 3);
  else
    write(1, "KO\n", 3);
  free_ab_stack(s);
  free_operations(o->head);
}

static void take_input(t_ab_stack *s, int visual, int color)
{
  t_operations *o;

  o = init_operations();
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
  apply_input(o, s, visual, color);
}

int main(int argc, char **argv)
{
  t_ab_stack *s;
  int visual;
  int color;
  int live;

  s = init_ab_stack(0, 0);
  visual = 0;
  color = 0;
  live = 0;
  argv = verify_bonuses(&argc, argv, &visual, &color, &live);
  if (argc == 1)
    exit(1);
  verify_number_errors(argc, argv);
  while (argc > 1)
  {
    s->a = stack_push(s->a, ft_atoi(argv[argc - 1]));
    argc--;
  }
  verify_duplicates(s->a);
  show_stack(s->a, s->b, "Init", visual, 0);
  if (!live)
    take_input(s, visual, color);
  else
    do_it_live(s);
  return 0;
}
// printf("END:%i\n", stack_end(a)->value);
// fflush(stdout);
// printf("BEGIN:%i\n", stack_begin(a)->value);
// fflush(stdout);
