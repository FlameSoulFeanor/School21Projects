/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:15:02 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 22:48:50 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	count_y(t_list_map *list, t_all *all)
{
	all->scene.map_size.y = 0;
	if (!list)
		return ;
	while (list)
	{
		all->scene.map_size.y++;
		list = list->next;
	}
}

void	make_more_map(t_list_map *list, char *array, int i, t_all *all)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(list->data))
	{
		array[j + i * all->scene.map_size.x] = list->data[j];
		j++;
	}
	while (j < all->scene.map_size.x)
	{
		array[j + i * all->scene.map_size.x] = ' ';
		j++;
	}
}

void	find_max_len(t_list_map *list, t_all *all)
{
	all->scene.map_size.x = 0;
	if (!list)
		return ;
	while (list)
	{
		if ((int)ft_strlen(list->data) > all->scene.map_size.x)
			all->scene.map_size.x = ft_strlen(list->data);
		list = list->next;
	}
}

void	create_map_array(t_list_map *list, t_all *all)
{
	char	*array;
	int		i;

	array = malloc(sizeof(char *) * all->scene.map_size.y
			* all->scene.map_size.x);
	if (!array)
		ft_errors(6, all);
	i = 0;
	while (i < all->scene.map_size.y && list)
	{
		make_more_map(list, array, i, all);
		list = list->next;
		i++;
	}
	all->scene.map = array;
}

void	map_create_all(t_list_map *list, t_all *all)
{
	find_max_len(list, all);
	count_y(list, all);
	create_map_array(list, all);
	free_list_map(list);
	map_check(all);
}
