#include "pipex.h"

void	cmd1_process(int pipefd[2], )
{
	dup2(input_file, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_process()
}

void	cmd2_process()
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2()
}

void	pipe_process(int p_fd[2])
{
	int	pid1;
	int	pid2;

	pid1 = fork();
	pid2 = fork();
	if (pid1 == -1 || pid2 == -1)
	{
		ft_printf("pipe creation error\n");
		exit(1);
	}
	if (pid1 == 0)
		cmd1_process();
	if (pid2 == 0)
		cmd2_process();
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
