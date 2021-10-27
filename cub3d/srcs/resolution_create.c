/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:00:56 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:15:13 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_num(char *str)
{
	if (!str)
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (!*str)
		return (1);
	return (0);
}

void	resolution_create(char *line, t_all *all)
{
	char	**str;

	str = ft_split(line + 2, ' ');
	if (!str)
		ft_errors(6, all);
	check_nbr_arg(str, 2, all);
	if (!str[0] || !str[1] || !check_num(str[0]) || !check_num(str[1]))
		ft_errors(9, all);
	all->scene.resol.x = ft_atoi(str[0]);
	all->scene.resol.y = ft_atoi(str[1]);
	if (abs(all->scene.resol.x) > MAX_X)
		all->scene.resol.x = MAX_X;
	if (abs(all->scene.resol.x) < MIN_X)
		all->scene.resol.x = MIN_X;
	if (abs(all->scene.resol.y) > MAX_Y)
		all->scene.resol.y = MAX_Y;
	if (abs(all->scene.resol.y) < MIN_Y)
		all->scene.resol.y = MIN_Y;
	free_split(str);
}
