#include "pipex.h"

void	execute_command(char **cmd_args, char **envp)
{
	char	*path;

	if (!cmd_args || !cmd_args[0])
	{
		ft_putstr_fd("Empty command\n", 2);
		exit(1);
	}
	path = find_command_path(cmd_args[0], envp);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putchar_fd('\n', 2);
		exit(127);
	}
	execve(path, cmd_args, envp);
	perror("execve failed");
	free(path);
	exit(1);
}
