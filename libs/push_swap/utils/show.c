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

static int		show_stack_init(char *title, int visual, int color)
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

static t_stack	*show_single_stack(t_stack *s, int *size)
{
	char *str;

	if ((str = ft_itoa(s->value)) == 0)
		ft_error("Malloc12 failed");
	*size = ft_strlen(str);
	write(1, str, *size);
	return (s->prev);
}

void			show_stack(t_ab_stack *s, char *title, int vis, int color)
{
	int		first_size;
	t_stack	*a;
	t_stack	*b;

	if (!show_stack_init(title, vis, color))
		return ;
	a = stack_end(s->a);
	b = stack_end(s->b);
	while (a != 0 || b != 0)
	{
		first_size = 0;
		if (a != 0)
			a = show_single_stack(a, &first_size);
		write(1, "            ", 12 - first_size);
		if (b != 0)
			b = show_single_stack(b, &first_size);
		write(1, "\n", 1);
	}
	write(1, "-------------------\n", 20);
	write(1, "\033[0;37m", 8);
}

static void		show_total_steps(int i, int visual)
{
	char *str;

	if (visual == 0)
		return ;
	if ((str = ft_itoa(i)) == 0)
		ft_error("Malloc13 failed");
	write(1, "Total steps: ", 13);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void			show_operations(t_operations *o, int visual, int color)
{
	int i;

	i = 0;
	while (o->next != 0 && o->line != 0)
	{
		if (visual && o->next->next != 0)
			show_stack(o->s, o->line, 1, 0);
		else if (visual && o->next->next == 0)
			show_stack(o->s, o->line, 1, color);
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
