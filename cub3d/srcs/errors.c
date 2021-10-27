/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:25:24 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:22:53 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_errors(int ind, t_all *all)
{
	all->errors.error = 1;
	if (ind == 1)
		all->errors.error_args = 1;
	if (ind == 2)
		all->errors.error_ceil = 1;
	if (ind == 3)
		all->errors.error_floor = 1;
	if (ind == 4)
		all->errors.error_config = 1;
	if (ind == 5)
		all->errors.error_map = 1;
	if (ind == 6)
		all->errors.error_memory = 1;
	if (ind == 7)
		all->errors.error_mlx = 1;
	if (ind == 8)
		all->errors.error_read = 1;
	if (ind == 9)
		all->errors.error_resolution = 1;
	if (ind == 10)
		all->errors.error_texture = 1;
	game_over(all);
}
