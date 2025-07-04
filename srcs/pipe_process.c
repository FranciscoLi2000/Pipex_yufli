#include "pipex.h"

void	cmd1_process(int pipefd[2], int input_fd, char *cmd, char **envp)
{
	dup2(input_fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(input_fd);
	execute_command(cmd, envp);
}

void	cmd2_process(int pipefd[2], int output_fd, char *cmd, char **envp)
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(output_fd);
	execute_command(cmd, envp);
}

void	pipe_process(int p_fd[2], int fd1, int fd2, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork 1 fail");
		exit(1);
	}
	if (pid1 == 0)
	{
		cmd1_process(p_fd, fd1, argv[2], envp);
		exit(1);
	}
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork 2 fail");
		exit(1);
	}
	if (pid2 == 0)
	{
		cmd2_process(p_fd, fd2, argv[3], envp);
		exit(1);
	}
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
