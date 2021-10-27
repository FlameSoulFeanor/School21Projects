#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef	struct s_steps
{
	int	count_a;
	int	count_b;
	int	dest_a;
	int	dest_b;
}	t_steps;


typedef	struct s_stack
{
	int	data;
	int	step;
	int	rotate;
	struct s_stack *next;
}	t_stack;


typedef struct s_stacks
{
	int median;
	int count_a;
	int	count_b;
	int	count;
	int	min;
	int	max;
	t_stack *b;
	t_stack *a;
}	t_stacks;

void	errors(void);
int		is_sorted(int *buff, t_stacks *all);
void	quick_sort(int *array, int start, int end);
void	find_duplicate(const int *array, int count);
void	sort_stack(t_stacks *all);

void	sa(t_stack *a, int i);
void	sb(t_stack *b, int i);
void	ss(t_stacks *all, int i);

void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rra(t_stack **a, int i);
void	rrb(t_stack **b, int i);
void	rr(t_stacks *all, int i);
void	rrr(t_stacks *all, int i);

void	pb(t_stacks *all, int i);
void	pa(t_stacks *all, int i);

void	three_element_sort(t_stacks *all);
void	five_element_sort(t_stacks *all);
void	all_sort(t_stacks *all);
void	main_sort(t_stacks *stacks);

void	ft_steps_markup(t_stack *stack, int count);
void	ft_minimum_insertion_steps(t_stacks *stacks, t_steps *steps);
void	ft_instruction_execution(t_stacks *stacks, t_steps *steps);
int 	ft_count_to_min(t_stack *a, int min);
int 	ft_finding_place(t_stacks *stacks, t_stack *b, t_steps *steps, int min);
void	ft_help_finding_place(t_stacks *stacks, t_stack *b, int *action, int *buffer);
int ft_smaller_element_detection(t_stack *a, int buffer, int src);

#endif