#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

void	execute_command(char *cmd, char **envp);
int		open_infile(char *filename);
int		open_outfile(char *filename);
void	child_process_1(int infile_fd, int pipefd[2], char *cmd, char **envp);
void	child_process_2(int outfile_fd, int pipefd[2], char *cmd, char **envp);
void	ft_perror_exit(const char *msg);

#endif
