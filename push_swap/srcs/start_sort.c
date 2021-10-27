#include "../includes/push_swap.h"

// ft_instruction_execution - функция которая выполняет дкействия по заданым ранее параметрам.

void	ft_instruction_execution(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ra(&stacks->a, 1);
		else
			rra(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			rb(&stacks->b, 1);
		else
			rrb(&stacks->b, 1);
		steps->count_b--;
	}
	pa(stacks, 1);
}

// ft_steps_markup - разметка каждого элемента стека кол-вом шагов которое нужно,
// чтобы элемент попал наверх стэка(на первую позицию)

void	ft_steps_markup(t_stack *stack, int count)
{
	int	i;
	int	iter;
	t_stack *buffer;

	i = -1;
	iter = count / 2;
	buffer = stack;
	while (++i <= iter)
	{
		buffer->step = i;
		buffer->rotate = 1;
		buffer = buffer->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buffer->step = i;
		buffer->rotate = -1;
		buffer = buffer->next;
	}
}

void	main_sort(t_stacks *stacks)
{
	t_steps	*step;

	step = malloc(sizeof(t_steps));
	while (stacks->count_b != 0)
	{
		step->count_a = -1;
		step->count_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		ft_steps_markup(stacks->a, stacks->count_a);
		ft_steps_markup(stacks->b, stacks->count_b);
		ft_minimum_insertion_steps(stacks, step);
		ft_instruction_execution(stacks, step);
	}
	if ((ft_count_to_min(stacks->a, stacks->min)) > stacks->count_a / 2)
		while (stacks->a->data != stacks->min)
			rra(&stacks->a, 1);
	else
		while (stacks->a->data != stacks->min)
			ra(&stacks->a, 1);
	free(step);
}

// ft_minimum_insertion_steps - функция которая находит элемент который можно перебросить минимальным кол-вом шагов.

void	ft_minimum_insertion_steps(t_stacks *stacks, t_steps *steps)
{
	int 	min_action;
	t_stack *first_a;
	t_stack *first_b;

	min_action = -1;
	first_a = stacks->a;
	first_b = stacks->b;
	while (stacks->b)
	{
		min_action = ft_finding_place(stacks, stacks->b, steps, min_action);
		stacks->a = first_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = first_b;
}

// ft_finding_place - функция после нахождения места вставки записывает данные в структуру steps, которая после выполнится
// в функции ft_instruction_execution тем самым вставит элемент в нужное место с наименьшим количеством действий.

int 	ft_finding_place(t_stacks *stacks, t_stack *b, t_steps *steps, int min)
{
	int action;
	int res;
	int buffer;

	action = 0;
	buffer = 0;
	ft_help_finding_place(stacks, b, &action, &buffer);
	if (stacks->a->rotate == -1)
		action = stacks->count_a - action;
	if (min  == 1 || (action + b->step) < min)
	{
		steps->dest_a = stacks->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

// ft_help_finding_place - вспомогательная функция для ft_finding_place. В данной функции происходит поиск наилучшей позиции для вставки

void	ft_help_finding_place(t_stacks *stacks, t_stack *b, int *action, int *buffer)
{
	while (stacks->a)
	{
		*buffer	= stacks->a->data;
		if (b->data > stacks->a->data)
		{
			*action += 1;
			if (b->data < stacks->a->next->data)
				break ;
			stacks->a = stacks->a->next;
		}
		else
			break ;
	}
	if (ft_smaller_element_detection(stacks->a, *buffer, b->data) == 1)
	{
		while (stacks->a)
		{
			if (stacks->a->data < *buffer && stacks->a->data > b->data)
				break ;
			*action += 1;
			stacks->a = stacks->a->next;
		}
	}
}

// ft_smaller_element_detection - функция сравнивает найденное место с другим, дабы найти место получше куда можно вставить элемент

int ft_smaller_element_detection(t_stack *a, int buffer, int src)
{
	t_stack *save;
	int ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->data < buffer && save->data > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

// ft_count_to_min - функция возвращает положение минимального элемента(числа) в стеке.

int 	ft_count_to_min(t_stack *a, int min)
{
	int i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
