/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ab_stack	*find_operation3(t_ab_stack *s, char *line)
{
  if (ft_strcmp(line, "rra"))
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


t_ab_stack	*find_operation2(t_ab_stack *s, char *line)
{
  if (ft_strcmp(line, "pb"))
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
  return find_operation3(s, line);
}

t_ab_stack	*find_operation(t_ab_stack *s, char *line)
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
  return find_operation2(s, line);
}

char		*malloc_operation(char *operation)
{
  char *ret;

  if ((ret = ft_strdup(operation)) == 0)
    ft_error("Malloc failed");
  return ret;
}
