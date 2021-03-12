/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_algo4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

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
