#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct s_args
{
	int		status;
	int		out_file;
	int		in_file;
	int		fd[2];
	char	*inFile;
	char	*outFile;
	char	**cmd1;
	char	**cmd2;
	char	**all_paths;
}	t_args;

void	error(char *str, int exit_code);
void	pipe_create(t_args	*all, char **envp);

#endif