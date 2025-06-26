#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;
	int	fd[2];
	char	tmp[100];

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			scanf("%s", tmp);
			write(fd[1], tmp, sizeof(tmp));
		}
	}
	else if (pid > 0)
	{
		close(fd[1]);
		while (1)
		{
			read(fd[0], tmp, sizeof(tmp));
			printf("%s", tmp);
		}
	}
	return (0);
}
