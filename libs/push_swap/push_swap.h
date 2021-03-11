#ifndef PUSH_SWAP_LIB
#define PUSH_SWAP_LIB

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft_plus/libft.h"

#define p(x) //write(1, x, 1);

typedef struct s_stack
{
	int value;
	int number;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

//To enable return of two stacks. Pointers do not work on empty stacks as they point on NULL
typedef struct s_ab_stack
{
	struct s_stack *a;
	struct s_stack *b;
} t_ab_stack;

typedef struct s_operations
{
	char *line;
	t_ab_stack *s;
	struct s_operations *next;
	struct s_operations *head;
} t_operations;

typedef struct s_sorted_chain
{
	int start;
	int end;
	int len;
	struct s_sorted_chain *next;
	struct s_sorted_chain *head;
} t_sorted_chain;

t_stack *stack_init(int value);
t_stack *stack_end(t_stack *stack);
t_stack *stack_begin(t_stack *stack);
t_stack *stack_push(t_stack *stack, int value);
t_stack *stack_pop(t_stack *stack);
void show_stack(t_stack *stack, t_stack *b, char *title, int color);
void free_stack(t_stack *s);
void free_ab_stack(t_ab_stack *s);
void free_operations(t_operations *o);
void free_sorted_chain(t_sorted_chain *sc);

t_stack *ft_s(t_stack *a);
t_ab_stack *ft_pa(t_ab_stack *s);
t_ab_stack *ft_pb(t_ab_stack *s);
t_stack *ft_r(t_stack *a);
t_stack *ft_rr(t_stack *a);

t_ab_stack *find_operation(t_ab_stack *s, char *line);
int is_sorted(t_stack *a, t_stack *b);
void verify_duplicates2(int value, t_stack *s);
void verify_duplicates(t_stack *a);
void verify_number_errors(int argc, char **argv);
char **verify_bonuses(int *argc, char **argv, int *vis, int *color, int *live);
void show_operations(t_operations *o, int visual, int color);
char *malloc_operation(char *operation);

t_stack *stack_position(t_stack *s, int number);
int stack_highest_value_pos(t_stack *s);
t_stack *stack_next(t_stack *s);
int ideal_next(t_stack *a);
int ideal_next2(t_stack *a, int ideal);
t_stack *stack_copy(t_stack *a);
int get_position_from_value(t_stack *a, int value);

int all_ordered(t_stack *a, t_stack *b);
int longest_chain_dir(t_stack *a);
char *shortest_path_to_correct_placement(t_stack *a);
char *b_values_ideal_position_a(t_stack *a, t_stack *b);
char *top_smaller_than_second(t_stack *a, t_stack *b);
char *top_greater_than_second(t_stack *a);
t_ab_stack *ab_stack_copy(t_ab_stack *s);

#endif
