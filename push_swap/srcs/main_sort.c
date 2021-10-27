/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 19:53:53 by hfunctio          #+#    #+#             */
/*   Updated: 2021/08/31 14:48:47 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	all_sort(t_stacks *all)
{
	while (all->count_a > 2)
	{
		if (all->a->data != all->min && all->a->data != all->max)
		{
			pb(all, 1);
			if (all->b->data > all->median)
				rb(&all->b, 1);
		}
		else
			ra(&all->a, 1);
	}
	if (all->a->data < all->a->next->data)
		sa(all->a, 1);
	pa(all, 1);
	main_sort(all);
}
