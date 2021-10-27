#include "../includes/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
}

int	ft_strfind(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strfind_ls_char(char *s, char *to_find)
{
	int		i;

	if (!s || !to_find)
		return (0);
	i = 0;
	while (s[i])
	{
		if (ft_strfind(to_find, s[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_strfind_c(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}


void	get_file(t_all *all, int fd, int ret)
{
	char *line;

	line = NULL;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (!ret)
			break ;
		if (ft_strfind_ls_char(line, "01PCE") == -1)
			errors(1, all);
		if (all->scene.map_size_x == -1)
			all->scene.map_size_x = (int)ft_strlen(line);
		else if (all->scene.map_size_x != (int)ft_strlen(line))
			errors(1, all);
		all->scene.map[all->scene.map_size_y] = ft_strdup(line);
		free(line);
		all->scene.map_size_y++;
	}
	all->scene.map[all->scene.map_size_y] = ft_strdup(line);
	all->scene.map_size_y++;
	free(line);
	close(fd);
}

void	create_map(char *file, t_all *all)
{
	int	fd;
	int	ret;
	char *line;

	ret = ft_strlen(file);
	if (ret < 4 || ft_strcmp(file + ret - 4, ".ber"))
		errors(1, all);
	ret = 0;
	fd = open(file, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		ret++;
	}
	free(line);
	all->scene.map = NULL;
	all->scene.map_size_x = -1;
	all->scene.map_size_y = 0;
	all->scene.map = malloc(sizeof(char *) * (ret + 1));
	close(fd);
	fd = open(file, O_RDONLY);
	get_file(all, fd, 0);
}
