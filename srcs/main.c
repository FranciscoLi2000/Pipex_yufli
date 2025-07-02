#include "pipex.h"

int	main(int argc, char **argv)
{
	int	pipefd[2];
	int	fd1;
	int	fd2;

	if (argc != 5)
	{
		ft_printf("Usage: %s file1 cmd1 cmd2 file2\n", argv[0]);
		return (1);
	}
	fd1 = open("input_file", O_RDONLY);
	fd2 = open("output_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fd1 || !fd2)
	{
		ft_printf("Cannot open files\n");
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		ft_printf("pipe fail\n");
		return (1);
	}
	pipe_process(pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
