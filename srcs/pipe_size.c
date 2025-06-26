#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;
	int	fd[2];
	char	c;
	int	count;

	count = 0;
	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == 0)
	{
		c = '%';
		close(fd[0]);
		while (1)
		{
			write(1, &c, 1);
			printf("%d chracters written\n", ++count);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	return (0);
}
