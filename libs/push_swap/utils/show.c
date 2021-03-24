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

static void show_goal3(t_goal *goal)
{
	char *str;

	write(1, "\nAll ordered to push: ", 22);
	if ((str = ft_itoa(goal->all_ordered_push)) == 0)
		ft_error("Malloc failed");
	write(1, str, ft_strlen(str));
	free(str);
	write(1, "\n-------------------\n", 21);
}

static void show_goal2(t_goal *goal)
{
	char *str;

	write(1, "\nMedian: ", 9);
	if ((str = ft_itoa(goal->median)) == 0)
		ft_error("Malloc failed");
	write(1, str, ft_strlen(str));
	free(str);
	write(1, "\nNumber to push: ", 17);
	if ((str = ft_itoa(goal->number_to_push)) == 0)
		ft_error("Malloc failed");
	write(1, str, ft_strlen(str));
	free(str);
	write(1, "\nPushed: ", 9);
	if ((str = ft_itoa(goal->pushed_number)) == 0)
		ft_error("Malloc failed");
	write(1, str, ft_strlen(str));
	free(str);
	write(1, "\nReturned number: ", 18);
	if ((str = ft_itoa(goal->returned_number)) == 0)
		ft_error("Malloc failed");
	write(1, str, ft_strlen(str));
	free(str);
	show_goal3(goal);
}

void show_goal(t_goal *goal, char *title)
{
	char s[2];
	char *str;

	write(1, "-------------------\n", 20);
	write(1, title, ft_strlen(title));
	write(1, "\n", 1);
	write(1, "Stack: ", 7);
	s[0] = goal->stack;
	s[1] = 0;
	write(1, s, 1);
	write(1, "\nPartition: ", 12);
	if ((str = ft_itoa(goal->partition)) == 0)
		ft_error("Malloc failed");
	write(1, str, ft_strlen(str));
	free(str);
	write(1, "\nPartition to push to: ", 23);
	if ((str = ft_itoa(goal->partition_to_push_to)) == 0)
		ft_error("Malloc failed");
	write(1, str, ft_strlen(str));
	free(str);
	show_goal2(goal);
}
