/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:09:01 by hfunctio          #+#    #+#             */
/*   Updated: 2021/08/12 16:48:35 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*get_path(char *cmd, t_args *all)
{
	char	*path;
	char	*command;
	int		i;
	int		fd;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	i = -1;
	while (all->all_paths[++i])
	{
		command = ft_strjoin("/", cmd);
		path = ft_strjoin(all->all_paths[i], command);
		fd = open(path, O_RDONLY);
		if (fd > -1)
		{
			close(fd);
			free(command);
			return (path);
		}
		free(command);
		free(path);
	}
	return (NULL);
}

static	void	init_cmd_2(t_args *all, char **envp)
{
	all->out_file = open(all->outFile, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (all->out_file == -1)
	{
		write(2, "pipex: ", 7);
		write(2, all->outFile, ft_strlen(all->outFile));
		write(2, ": ", 2);
		error(strerror(errno), 1);
	}
	close(all->fd[1]);
	dup2(all->out_file, STDOUT_FILENO);
	dup2(all->fd[0], STDIN_FILENO);
	close(all->fd[0]);
	if (execve(get_path(all->cmd2[0], all), all->cmd2, envp) == -1)
	{
		write(2, "pipex: ", 7);
		write(2, all->cmd2[0], ft_strlen(all->cmd2[0]));
		error(": command not found", 127);
	}
	exit(EXIT_SUCCESS);
}

/*
** execve() - системный вызов, загружает в процесс 
** другую программу и передает ей
** безвозвратное управление. 
** int execve(const char *PATH, const char **ARGV, const char **ENVP)
** PATH - это путь к исполняемому файлу программы, которая 
** будет запускаться внутри процесса.
** ARGV - массив аргументов программы
** ENVP - массив, содержащий окружение запускаемой программы
** dup2(int FD1, int FD2) - системный ваызов, позволяет 
** перенаправлять ввод-вывод 
** с дескриптора
** FD2 на дескриптор FD1.
*/
static void	init_cmd_1(t_args *all, char **envp)
{
	all->in_file = open(all->inFile, O_RDONLY);
	if (all->in_file == -1)
	{
		write(2, "pipex: ", 7);
		write(2, all->inFile, ft_strlen(all->inFile));
		error(": No such file or directory", EXIT_FAILURE);
	}
	else
	{
		close(all->fd[0]);
		dup2(all->in_file, STDIN_FILENO);
		dup2(all->fd[1], STDOUT_FILENO);
		close(all->fd[1]);
	}
	if (execve(get_path(all->cmd1[0], all), all->cmd1, envp) == -1)
	{
		write(2, "pipex: ", 7);
		write(2, all->cmd1[0], ft_strlen(all->cmd1[0]));
		error(": command not found", 127);
	}
}

/*
** fork()- системный вызов прендазначенный для 
** порождения нового процесса(unistd.h)
** fork порождает процесс методом "клонирования". Это озночает, 
** что новый процесс является точной
** копией своего родителя и выполняет ту же самую программу.
** pipe() - системныый вызов для создания канала. Интерфейс 
** канала представляет собой два связанных
** файловых дескриптора, один из которых предназначен для 
** записи данных, другой для чтения.
** Закрытие концов канала осуществляется при помощи системного вызова close().
*/

void	pipe_create(t_args	*all, char **envp)
{
	pid_t	pid_1;
	pid_t	pid_2;

	if (pipe(all->fd) == -1)
		error("Cant open pipe.", EXIT_FAILURE);
	pid_1 = fork();
	if (pid_1 < 0)
		error("Cant create forking child.", EXIT_FAILURE);
	else if (pid_1 == 0)
		init_cmd_1(all, envp);
	pid_2 = fork();
	if (pid_2 < 0)
		error("Cant create forking child.", EXIT_FAILURE);
	else if (pid_2 == 0)
		init_cmd_2(all, envp);
	else
	{
		close(all->fd[0]);
		close(all->fd[1]);
		waitpid(pid_1, &all->status, 0);
		waitpid(pid_2, &all->status, 0);
	}
}
