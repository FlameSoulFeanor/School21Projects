/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:31:04 by hfunctio          #+#    #+#             */
/*   Updated: 2021/06/17 16:58:49 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_mem(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

int		ret_null(char **line)
{
	*line = ft_strdup("");
	return (0);
}

int		find_n(int fd, char **line, char **rem)
{
	int		i;
	char	*tmp;

	i = 0;
	while (rem[fd][i] != '\n' && rem[fd][i] != '\0')
		i = i + 1;
	if (rem[fd][i] == '\n')
	{
		*line = ft_substr(rem[fd], 0, i);
		tmp = ft_strdup(rem[fd] + i + 1);
		free_mem(&rem[fd]);
		rem[fd] = tmp;
		if (rem[fd][0] == '\0')
			free_mem(&rem[fd]);
	}
	else
	{
		*line = ft_strdup(rem[fd]);
		free_mem(&rem[fd]);
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*rem[10000];
	char		*buff;
	char		*tmp;
	int			read_bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > 10000 ||
		(!(buff = (char*)malloc(BUFFER_SIZE + 1))))
		return (-1);
	while ((read_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_bytes] = '\0';
		if (!rem[fd])
			rem[fd] = ft_strdup("");
		tmp = ft_strjoin(rem[fd], buff);
		free_mem(&rem[fd]);
		rem[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (-1);
	free_mem(&buff);
	if (!rem[fd] && !read_bytes)
		return (ret_null(line));
	return (find_n(fd, line, rem));
}
