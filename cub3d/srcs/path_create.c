/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:42:01 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:11:32 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_split(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	free(str[count]);
	free(str);
}

static int	check_dis(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (1);
	if (str[0] == 'S' && str[1] == 'O')
		return (2);
	if (str[0] == 'W' && str[1] == 'E')
		return (3);
	if (str[0] == 'E' && str[1] == 'A')
		return (4);
	return (5);
}

static void	path_parse(char *str, int index, t_all *all)
{
	if (index == 1)
		all->scene.north_path.directory = ft_strdup(str);
	if (index == 2)
		all->scene.south_path.directory = ft_strdup(str);
	if (index == 3)
		all->scene.west_path.directory = ft_strdup(str);
	if (index == 4)
		all->scene.east_path.directory = ft_strdup(str);
	if (index == 5)
		all->scene.sprite_path.directory = ft_strdup(str);
}

void	check_nbr_arg(char **str, int num, t_all *all)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	if (count != num)
		ft_errors(1, all);
}

void	path_create(char *line, t_all *all)
{
	char	**str;

	str = ft_split(line, ' ');
	if (!str)
		ft_errors(6, all);
	check_nbr_arg(str, 2, all);
	if (!str[0] || !str[1])
		ft_errors(1, all);
	path_parse(str[1], check_dis(str[0]), all);
	free_split(str);
}
