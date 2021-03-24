/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft_plus/libft.h"

typedef struct	s_stack
{
	int				value;
	int				number;
	int partition;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_ab_stack
{
	struct s_stack	*a;
	struct s_stack	*b;
}				t_ab_stack;

typedef struct	s_operations
{
	char				*line;
	t_ab_stack			*s;
	struct s_operations	*next;
	struct s_operations	*head;
}				t_operations;

typedef struct	s_goal
{
	char stack;
	int partition;
	int partition_to_push_to;
	int median;
	int pushed_number;
	int number_to_push;
	int returned_number;
	int returning;
	int all_ordered_push;
} t_goal;

typedef struct	s_sorted_chain
{
	int						start;
	int						end;
	int						len;
	struct s_sorted_chain	*next;
	struct s_sorted_chain	*head;
}				t_sorted_chain;

typedef struct	s_bonus
{
	int	live;
	int	visual;
	int	color;
}				t_bonus;

t_stack			*stack_init(int value, int partition);
t_stack			*stack_end(t_stack *stack);
t_stack			*stack_begin(t_stack *stack);
t_stack			*stack_push(t_stack *stack, int value, int partition);
t_stack			*stack_pop(t_stack *stack);
void			show_stack(t_ab_stack *s, char *t, int v, int c);
void			free_stack(t_stack *s);
void			free_ab_stack(t_ab_stack *s);
void			free_operations(t_operations *o);
void			free_sorted_chain(t_sorted_chain *sc);
t_ab_stack		*init_ab_stack(t_stack *a, t_stack *b);
t_operations	*init_operations();

t_stack			*ft_s(t_stack *a);
t_ab_stack		*ft_pa(t_ab_stack *s, int partition);
t_ab_stack		*ft_pb(t_ab_stack *s, int partition);
t_stack			*ft_r(t_stack *a);
t_stack			*ft_rr(t_stack *a);

t_ab_stack		*find_operation(t_ab_stack *s, char *line, int partition);
int				is_sorted(t_stack *a, t_stack *b);
void			verify_duplicates2(int value, t_stack *s);
void			verify_duplicates(t_stack *a);
void			verify_number_errors(int argc, char **argv);
char			**verify_bonuses(int *argc, char **argv, t_bonus *bonus);
void			show_operations(t_operations *o, int visual, int color);
char			*malloc_operation(char *operation);

t_stack			*stack_position(t_stack *s, int number);
int				stack_highest_value_pos(t_stack *s);
int		stack_lowest_value_pos(t_stack *s);
int stack_biggest_value(t_stack *a);
t_stack			*stack_next(t_stack *s);
int				ideal_next(t_stack *a);
int				ideal_next2(t_stack *a, int ideal);
int is_inside_longest_chain(int value, t_stack *a, t_sorted_chain *sc);
t_stack			*stack_copy(t_stack *a);
int				get_position_from_value(t_stack *a, int value);
int		get_value_from_position(t_stack *a, int pos);
int	sa_ideal(t_stack *s);
int	sa_ideal2(t_stack *s, t_sorted_chain *sc);

int				ordered(t_stack *a);
int				all_ordered(t_stack *a, t_stack *b);
t_sorted_chain	*longest_chain(t_stack *a);
// char		*out_longest_chain(t_stack *a, t_stack *b, t_sorted_chain *sc);
char			*shortest_path_to_correct_placement(t_stack *a);
char		*shortest_path_to_correct_placementb(t_stack *a);
char	*goto_ideal_value_top_b(t_stack *a, t_stack *b);
char			*b_ideal_position_a(t_stack *a, t_stack *b);
// char			*top_smaller_than_second(t_stack *a, t_stack *b);
// char			*top_greater_than_second(t_stack *a, t_stack *b);
t_ab_stack		*ab_stack_copy(t_ab_stack *s);

// char *outside_longest_chain(t_stack *a, t_sorted_chain *sc);
// char *inside_longest_chain(t_stack *a, t_sorted_chain *sc);

char *fill_b(t_stack *a, t_goal *goal);
int	ideal_nextb(t_stack *a, t_stack *b, t_sorted_chain *sc);
int			is_sortedb(t_stack *b);
int			orderedb(t_stack *b);
int		smallest_value_num(t_stack *s);
int	ideal_nextb2(t_stack *a, t_stack *b);

void free_goal(t_goal *goal);
char *get_todo(t_goal *goal);
t_goal *init_goal();
t_goal *set_new_goal(t_goal *goal, int g);
int	ideal_nextb3(t_stack *a, int value);
t_goal *generate_todos(t_goal *goal);
char *goto_num(int pos, t_stack *a);


t_stack *partition_end(t_stack *s, int partition);
t_stack *partition_begin(t_stack *stack, int partition);
int partition_len(t_stack *stack, int partition);
int		smallest_value(t_stack *s, int partition);
int	next_smallest(t_stack *s, int value, int partition);
int find_median(t_stack *s, int partition);
void verify_goal(t_goal *goal, t_stack *a, t_stack *b, int debug);
t_goal *init_goal(t_stack *a, int debug);
int stack_len(t_stack *stack);
char *quicksort_a(t_stack *a, t_goal *goal);
char *quicksort_b(t_stack *b, t_goal *goal);
void show_goal(t_goal *goal, char *title);
int		stack_sorted(t_stack *a);
int		partition_sorted(t_stack *a, int partition);
int		partition_sortedb(t_stack *a, int partition);
char		*shortest_path_to_correct_placementb(t_stack *b);
int		stack_sortedb(t_stack *b);
int	sa_ideala(t_stack *a);
int	sa_idealb(t_stack *b);


#endif
