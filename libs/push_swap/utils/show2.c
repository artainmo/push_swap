/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
