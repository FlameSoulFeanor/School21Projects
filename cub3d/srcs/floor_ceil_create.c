/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:38:04 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/26 18:38:29 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	floor_create(t_all *all)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (i < all->scene.resol.x)
	{
		j = all->scene.resol.y / 2;
		while (j < all->scene.resol.y)
		{
			dst = all->image.data
				+ (j * all->image.line_size
					+ i * (all->image.bpp / 8));
			*(unsigned int *)dst = all->scene.floor_clr;
			j++;
		}
		i++;
	}
}

void	ceil_create(t_all *all)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (i < all->scene.resol.x)
	{
		j = 0;
		while (j < all->scene.resol.y / 2)
		{
			dst = all->image.data
				+ (j * all->image.line_size
					+ i * (all->image.bpp / 8));
			*(unsigned int *)dst = all->scene.ceil_clr;
			j++;
		}
		i++;
	}
}
