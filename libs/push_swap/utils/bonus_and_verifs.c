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
*/

static char	**live_bonus(int *argc, char **argv, int *live)
{
	*live = 1;
	*argc = *argc - 1;
	return (&argv[1]);
}

char		**verify_bonuses(int *argc, char **argv, int *vis, int *c, int *l)
{
	int i;

	i = 1;
	while (i < 3 && i < *argc)
	{
		if (ft_strcmp(argv[i], "-v"))
			*vis = 1;
		if (ft_strcmp(argv[i], "-c"))
			*c = 1;
		if (i == 1 && ft_strcmp(argv[i], "-l"))
			return (live_bonus(argc, argv, l));
		i++;
	}
	if (*vis && *c)
	{
		*argc = *argc - 2;
		return (&argv[2]);
	}
	else if (*vis || *c)
	{
		*argc = *argc - 1;
		return (&argv[1]);
	}
	return (&argv[0]);
}
