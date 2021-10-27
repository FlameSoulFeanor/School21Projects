/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:01:20 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/05 15:33:12 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stacks *all, int i)
{
	t_stack	*buff;

	all->count_a -= 1;
	all->count_b += 1;
	buff = all->a;
	all->a = all->a->next;
	buff->next = all->b;
	all->b = buff;
	if (i == 1)
		write(1, "pb\n", 3);
}

void	pa(t_stacks *all, int i)
{
	t_stack	*buff;

	all->count_a += 1;
	all->count_b -= 1;
	buff = all->b;
	all->b = all->b->next;
	buff->next = all->a;
	all->a = buff;
	if (i == 1)
		write(1, "pa\n", 3);
}
