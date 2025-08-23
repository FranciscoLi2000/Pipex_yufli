#include "pipex.h"

void	child_process_1(t_pipex *px, char *cmd)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
	{
		perror("Split failed (cmd1)");
		exit(1);
	}
	dup2(px->infile, STDIN_FILENO);
	dup2(px->pipefd[1], STDOUT_FILENO);
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	close(px->infile);
	execute_command(cmd_args, px->envp);
	free_str_array(cmd_args);
	exit(1);
}

void	child_process_2(t_pipex *px, char *cmd)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
	{
		perror("Split failed (cmd2)");
		exit(1);
	}
	dup2(px->pipefd[0], STDIN_FILENO);
	dup2(px->outfile, STDOUT_FILENO);
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	close(px->outfile);
	execute_command(cmd_args, px->envp);
	free_str_array(cmd_args);
	exit(1);
}

int	pipex(t_pipex *px, char **argv)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork1 fail");
		exit(1);
	}
	if (pid1 == 0)
		child_process_1(px, argv[2]);
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork2 fail");
		exit(1);
	}
	if (pid2 == 0)
		child_process_2(px, argv[3]);
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
