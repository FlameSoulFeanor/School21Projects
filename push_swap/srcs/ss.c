/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:08:09 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/05 18:18:24 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *a, int i)
{
	int	tmp;

	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int i)
{
	int	tmp;

	tmp = b->data;
	b->data = b->next->data;
	b->next->data = tmp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *all, int i)
{
	sa(all->a, 0);
	sb(all->b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	rrr(t_stacks *all, int i)
{
	if (i == 1)
		write(1, "rrr\n", 4);
	rra(&all->a, 0);
	rrb(&all->b, 0);
}
