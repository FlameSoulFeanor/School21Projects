/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:06:08 by hfunctio          #+#    #+#             */
/*   Updated: 2021/09/09 10:52:18 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	free_massive(char **all)
{
	int	i;

	i = -1;
	while (all[++i])
		free(all[i]);
	free(all);
}

static	void	free_leaks(t_args *all)
{
	if (all->inFile)
		free(all->inFile);
	if (all->outFile)
		free(all->outFile);
	if (all->cmd1)
		free_massive(all->cmd1);
	if (all->cmd2)
		free_massive(all->cmd2);
	if (all->all_paths)
		free_massive(all->all_paths);
}

static void	init_struct(char **argv, char **envp, t_args *all)
{
	char	*path;
	int		i;

	i = -1;
	all->inFile = ft_strdup(argv[1]);
	all->outFile = ft_strdup(argv[4]);
	all->cmd1 = ft_split(argv[2], ' ');
	all->cmd2 = ft_split(argv[3], ' ');
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			all->all_paths = ft_split(path, ':');
			free(path);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_args	all;

	if (argc != 5)
		error("Arguments error!!!", EXIT_FAILURE);
	init_struct(argv, envp, &all);
	pipe_create(&all, envp);
	free_leaks(&all);
	return (WEXITSTATUS(all.status));
}
