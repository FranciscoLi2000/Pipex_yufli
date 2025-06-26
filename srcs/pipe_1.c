#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int	main(void)
{
	int	fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid > 0)
	{
		close(fd[0]);
		sleep(5);
		write(fd[1], "ab", 2);
		while (1);
	}
	else if (pid == 0)
	{
		char ch[2];
		printf("Child process is waiting for the data of pipe... \n");
		close(fd[1]);
		read(fd[0], ch, 2);
		printf("read from pipe : %s\n", ch);
	}
	return (0);
}
