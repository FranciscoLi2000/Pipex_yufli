#include "pipex.h"

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		ft_printf("Invalid command\n");
		exit(1);
	}
	path = find_command_path(args[0]);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(args[0], 2);
		free_split(args);
		exit(127);
	}
	execve(path, args, envp);
	perror("execve failed");
	free_split(args);
	free(path);
	exit(1);
}
