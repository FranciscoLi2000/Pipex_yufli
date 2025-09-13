#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	px.infile = open(argv[1], O_RDONLY);
	px.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	px.envp = envp;
	if (px.infile == -1 || px.outfile == -1)
	{
		perror("Error opening file");
		return (1);
	}
	if (pipe(px.pipefd) == -1)
	{
		perror("Pipe failed");
		return (1);
	}
	pipex(&px, argv);
	close(px.pipefd[0]);
	close(px.pipefd[1]);
	close(px.infile);
	close(px.outfile);
	return (0);
}
