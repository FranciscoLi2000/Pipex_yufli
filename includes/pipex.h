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
# include <stdio.h>

void	free_split(char **args);
char	*find_command_path(char *cmd);
void	execute_command(char *cmd, char **envp);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strcat(char *s1, char *s2);
void	cmd1_process(int pipefd[2], int input_fd, char *cmd, char **envp);
void	cmd2_process(int pipefd[2], int output_fd, char *cmd, char **envp);
void	pipe_process(int p_fd[2], int fd1, int fd2, char **argv, char **envp);

#endif
