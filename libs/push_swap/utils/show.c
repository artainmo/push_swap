/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	show_stack_init(char *title, int visual, int color)
{
	if (visual == 0)
		return (0);
	if (color == 1)
		write(1, "\033[0;36m", 8);
	write(1, "-------------------\n", 20);
	write(1, title, ft_strlen(title));
	write(1, "\n", 1);
	write(1, "stack a     stack b\n", 20);
	return (1);
}

void		show_stack(t_stack *a, t_stack *b, char *title, int vis, int color)
{
	char *first;

	if (!show_stack_init(title, vis, color))
		return ;
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

static void	show_total_steps(int i, int visual)
{
	char *str;

	if (visual == 0)
		return ;
	if ((str = ft_itoa(i)) == 0)
		ft_error("Malloc failed");
	write(1, "Total steps: ", 13);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void		show_operations(t_operations *o, int visual, int color)
{
	int i;

	i = 0;
	while (o->next != 0 && o->line != 0)
	{
		if (visual && o->next->next != 0)
			show_stack(o->s->a, o->s->b, o->line, 1, 0);
		else if (visual && o->next->next == 0)
			show_stack(o->s->a, o->s->b, o->line, 1, color);
		else
		{
			write(1, o->line, ft_strlen(o->line));
			write(1, "\n", 1);
		}
		o = o->next;
		i++;
	}
	show_total_steps(i, visual);
}
