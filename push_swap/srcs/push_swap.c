/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:26:43 by hfunctio          #+#    #+#             */
/*   Updated: 2021/08/31 13:42:58 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	list_create(int *buff, t_stacks *all)
{
	int	i;
	t_stack *tmp;
	t_stack *list;

	i = 0;
	all->b = NULL;
	tmp = malloc(sizeof(t_stack));
	list = tmp;
	while (i < all->count)
	{
		if (i < (all->count - 1))
			tmp->next = malloc(sizeof(t_stack));
		tmp->data = buff[i];
		if (i == (all->count - 1))
			tmp->next = NULL;
		else
			tmp = tmp->next;
		i++;
	}
	all->a = list;
}

static void check_duplicates(int argc, char **argv, t_stacks *all)
{
	int i;
	int j;
	int *array;

	i = 0;
	j = 0;
	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		errors();
	while (++i < argc)
	{
		array[j] = ft_atoi(argv[i]);
		if (!array[j])
			errors();
		j++;
	}
	quick_sort(array, 0, argc - 2);
	find_duplicate(array, argc - 1);
	all->count_a = argc - 1;
	all->count = argc - 1;
	all->count_b = 0;
	all->min = array[0];
	all->max = array[argc - 2];
	all->median = array[(argc - 1) / 2];
	free(array);
}

static void	check_arguments(int argc, char **argv)
{
	if (argc < 2)
		errors();
	argv++;
	while (*argv)
	{
		if (!ft_isdigit(**argv))
			errors();
		argv++;
	}
}

int	main(int argc, char **argv)
{
	int			*buff;
	t_stacks	*all;
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	buff = malloc(sizeof(int) * (argc - 1));
	all = malloc(sizeof(t_stacks));
	check_arguments(argc, argv);
	check_duplicates(argc, argv, all);
	while (++i < argc)
	{
		buff[j] = ft_atoi(argv[i]);
		j++;
	}
	if (is_sorted(buff, all))
	{
		list_create(buff, all);
		sort_stack(all);
	}
	free(all);
	free(buff);
	return (0);
}
