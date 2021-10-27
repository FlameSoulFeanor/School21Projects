/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:54:16 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/05 17:10:03 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_element_sort(t_stacks *all)
{
	if (all->count == 1)
		return ;
	else if (all->count == 2)
	{
		if (all->a->data > all->a->next->data)
			sa(all->a, 1);
		return ;
	}
	else if (all->count == 3)
	{
		if (all->a->data == all->max)
			ra(&all->a, 1);
		if (all->a->next->data == all->max)
			rra(&all->a, 1);
		if (all->a->data > all->a->next->data)
			sa(all->a, 1);
	}
}

void	five_element_sort(t_stacks *all)
{
	while (all->count_b < 2)
	{
		if (all->a->data == all->min || all->a->data == all->max)
			pb(all, 1);
		else
			ra(&all->a, 1);
	}
	three_element_sort(all);
	pa(all, 1);
	pa(all, 1);
	if (all->a->data == all->max)
		ra(&all->a, 1);
	else
	{
		sa(all->a, 1);
		ra(&all->a, 1);
	}
}
