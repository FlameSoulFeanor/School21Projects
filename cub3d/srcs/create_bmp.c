/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:54:26 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 18:49:07 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_more(unsigned char *array_bmp, t_all *all)
{
	array_bmp[10] = (unsigned char)(54);
	array_bmp[14] = (unsigned char)(40);
	array_bmp[18] = (unsigned char)(all->scene.resol.x % 256);
	array_bmp[19] = (unsigned char)(all->scene.resol.x / 256 % 256);
	array_bmp[20] = (unsigned char)(all->scene.resol.x / 256 / 256 % 256);
	array_bmp[21] = (unsigned char)(all->scene.resol.x / 256 / 256 / 256 % 256);
	array_bmp[22] = (unsigned char)(all->scene.resol.y % 256);
	array_bmp[23] = (unsigned char)(all->scene.resol.y / 256 % 256);
	array_bmp[24] = (unsigned char)(all->scene.resol.y / 256 / 256 % 256);
	array_bmp[25] = (unsigned char)(all->scene.resol.y / 256 / 256 / 256 % 256);
	array_bmp[26] = (unsigned char)(1);
	array_bmp[28] = (unsigned char)(32);
}

static void	bmp_init(unsigned char *array_bmp, t_all *all)
{
	int	i;

	i = -1;
	while (++i < 54)
		array_bmp[i] = (unsigned char)(0);
	array_bmp[0] = (unsigned char)(66);
	array_bmp[1] = (unsigned char)(77);
	array_bmp[2] = (unsigned char)((4 * all->scene.resol.y
				* all->scene.resol.x + 54) % 256);
	array_bmp[3] = (unsigned char)((4 * all->scene.resol.y
				* all->scene.resol.x + 54) / 256 % 256);
	array_bmp[4] = (unsigned char)((4 * all->scene.resol.y
				* all->scene.resol.x + 54) / 256 / 256 % 256);
	array_bmp[5] = (unsigned char)((4 * all->scene.resol.y
				* all->scene.resol.x + 54) / 256 / 256 / 256 % 256);
	init_more(array_bmp, all);
}

static void	bmp_print(int fd, t_all *all)
{
	int				i;
	int				j;
	int				coor;
	int				k;
	unsigned char	c;

	i = all->scene.resol.y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < all->scene.resol.x)
		{
			coor = i * all->image.line_size + 4 * j;
			k = 0;
			while (k < 4)
			{
				c = (unsigned char)all->image.data[coor + k];
				write(fd, &c, 1);
				k++;
			}
			j++;
		}
		i--;
	}
}

void	create_bmp(t_all *all)
{
	unsigned char	array_bmp[54];
	int				fd;

	bmp_init(array_bmp, all);
	fd = open("cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	write(fd, &array_bmp, 54);
	bmp_print(fd, all);
	close(fd);
	game_over(all);
}
