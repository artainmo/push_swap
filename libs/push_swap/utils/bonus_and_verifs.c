/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_and_verifs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		verify_duplicates2(int value, t_stack *s)
{
	t_stack *loop;

	loop = s;
	while (loop != 0)
	{
		if (loop->value == value)
			ft_error("Error");
		loop = loop->next;
	}
}

void		verify_duplicates(t_stack *a)
{
	t_stack *loop;

	loop = a;
	while (loop != 0)
	{
		verify_duplicates2(loop->value, loop->next);
		loop = loop->next;
	}
}

void		verify_number_errors(int argc, char **argv)
{
	while (argc > 1)
	{
		if (!ft_str_isdigit(argv[argc - 1]) || (!ft_atoi(argv[argc - 1])
					&& ft_strlen(argv[argc - 1]) != 1))
			ft_error("Error");
		argc--;
	}
}

/*
**Live let you make changes and visualize them right after each operation
**Live is used in checker
**Debug -d is used in push_swap to view in slow stack after each step
*/

static char	**live_bonus(int *argc, char **argv, t_bonus *b)
{
	b->live = 1;
	b->visual = 1;
	*argc = *argc - 1;
	return (&argv[1]);
}

char		**verify_bonuses(int *argc, char **argv, t_bonus *b)
{
	int i;

	i = 1;
	while (i < 3 && i < *argc)
	{
		if (ft_strcmp(argv[i], "-v"))
			b->visual = 1;
		if (ft_strcmp(argv[i], "-c"))
			b->color = 1;
		if (i == 1 && (ft_strcmp(argv[i], "-l") || ft_strcmp(argv[i], "-d")))
			return (live_bonus(argc, argv, b));
		i++;
	}
	if (b->visual && b->color)
	{
		*argc = *argc - 2;
		return (&argv[2]);
	}
	else if (b->visual || b->color)
	{
		*argc = *argc - 1;
		return (&argv[1]);
	}
	return (&argv[0]);
}
