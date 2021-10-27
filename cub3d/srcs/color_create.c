/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:24:41 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 22:00:01 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	color_pars(char **str, char place, t_all *all)
{
	if (place == 'C')
		all->scene.ceil_clr
			= (ft_atoi(str[2]) | ft_atoi(str[1]) << 8 | ft_atoi(str[0]) << 16);
	else
		all->scene.floor_clr
			= (ft_atoi(str[2]) | ft_atoi(str[1]) << 8 | ft_atoi(str[0]) << 16);
}

void	color_create(char *line, t_all *all)
{
	char	**str;
	char	**clr;

	str = ft_split(line, ' ');
	if (!str)
		ft_errors(6, all);
	check_nbr_arg(str, 2, all);
	clr = ft_split(str[1], ',');
	if (!clr)
		ft_errors(6, all);
	check_nbr_arg(clr, 3, all);
	if (!clr[0] || !clr[1] || !clr[2]
		|| !check_num(clr[0]) || !check_num(clr[1]) || !check_num(clr[2]))
		ft_errors(4, all);
	color_pars(clr, line[0], all);
	free_split(clr);
	free_split(str);
}
