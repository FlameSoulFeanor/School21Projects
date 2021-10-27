/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:31:04 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 15:10:26 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*on_save(char *str)
{
	int		i;
	int		j;
	char	*str_out;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	str_out = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!str_out)
		return (0);
	i++;
	while (str[i])
		str_out[j++] = str[i++];
	str_out[j] = '\0';
	free(str);
	return (str_out);
}

char	*trimn_to_line(char *str)
{
	char	*str_out;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	str_out = malloc(sizeof(char) * (i + 1));
	if (!str_out)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str_out[i] = str[i];
		i++;
	}
	str_out[i] = '\0';
	return (str_out);
}

int	check(int file_read, char **line, char *str_out)
{
	if (!(*line))
	{
		free(*line);
		*line = ft_strdup("");
	}
	if (file_read < 0)
		return (-1);
	if (!file_read && !str_out)
		return (0);
	return (1);
}

int	get_next_loop(char *buffer, char **str_out, int file_read)
{
	char	*tmp;

	buffer[file_read] = '\0';
	if (!(*str_out))
		*str_out = ft_strdup("");
	tmp = ft_strjoin(*str_out, buffer);
	free(*str_out);
	*str_out = tmp;
	if (ft_strchr(*str_out, '\n') != NULL)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*str_out;
	int			file_read;

	if (fd < 0 || !line)
		return (-1);
	buffer = malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (-1);
	file_read = read(fd, buffer, 1);
	while (file_read > 0)
	{
		if (get_next_loop(buffer, &str_out, file_read))
			break ;
		file_read = read(fd, buffer, 1);
	}
	free(buffer);
	*line = trimn_to_line(str_out);
	str_out = on_save(str_out);
	return (check(file_read, line, str_out));
}
