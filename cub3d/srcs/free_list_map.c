/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:49:20 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 19:12:24 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_list_map(t_list_map *list)
{
	t_list_map	*next;

	next = list;
	while (next)
	{
		next = list->next;
		free(list->data);
		free(list);
		list = next;
	}
}
