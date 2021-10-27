/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:01:51 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/05 19:56:20 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_duplicate(const int *array, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (array[i] == array[i + 1])
			errors();
		else if(array[i] > MAX_INT || array[i] <= MIN_INT)
			errors();
		i++;
	}
}

int	sort(int *array, int start, int end)
{
	int	i;
	int	j;
	int	tmp;
	int	last;

	last = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= last)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = tmp; 
	return (i + 1);
}

void	quick_sort(int *array, int start, int end)
{
	int	i;

	if (start < end)
	{
		i = sort(array, start, end);
		quick_sort(array, start, i - 1);
		quick_sort(array, i + 1, end);
	}
}

int	is_sorted(int *buff, t_stacks *all)
{
	int	i;

	i = 0;
	while (i < (all->count - 1))
	{
		if (buff[i] > buff[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sort_stack(t_stacks *all)
{
	if (all->count <= 3)
		three_element_sort(all);
	else if (all->count <= 5)
		five_element_sort(all);
	else
		all_sort(all);
}
