/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:57:27 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/05 18:09:24 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrb(t_stack **b, int i)
{
	t_stack	*first_list;
	t_stack	*before_last;
	t_stack	*rotate;

	first_list = *b;
	before_last = *b;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	rotate = before_last->next;
	before_last->next = NULL;
	rotate->next = first_list;
	*b = rotate;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rra(t_stack **a, int i)
{
	t_stack *first_list;
	t_stack	*before_last;
	t_stack	*rotate;

	first_list = *a;
	before_last = *a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	rotate = before_last->next;
	before_last->next = NULL;
	rotate->next = first_list;
	*a = rotate;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ra(t_stack **a, int i)
{
	t_stack	*first_list;
	t_stack	*last_list;
	t_stack	*rotate;

	rotate = *a;
	first_list = (*a)->next;
	last_list = *a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate->next = NULL;
	last_list->next = rotate;
	*a = first_list;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
{
	t_stack	*first_list;
	t_stack	*last_list;
	t_stack	*rotate;

	rotate = *b;
	first_list = (*b)->next;
	last_list = *b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate->next = NULL;
	last_list->next = rotate;
	*b = first_list;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stacks *all, int i)
{
	if (i == 1)
		write(1, "rr\n", 3);
	ra(&all->a, 0);
	rb(&all->b, 0);
}
