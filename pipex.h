#ifndef PIPEX_H
# define PIPEX_H

/*==============================*/
/*		INCLUDES	*/
/*==============================*/

# include <unistd.h>     // write, read, fork, execve, pipe, access, dup2, close
# include <stdlib.h>     // malloc, free, exit
# include <fcntl.h>      // open
# include <sys/wait.h>   // wait, waitpid
# include <stdio.h>      // perror (可选)
# include <string.h>     // strerror (可选)

/*==============================*/
/*		STRUCTURES	*/
/*==============================*/
typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**cmd1_args;
	char	**cmd2_args;
	char	**envp;
}	t_pipex;

/*==============================*/
/*	UTILITY FUNCTIONS	*/
/*==============================*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	free_str_array(char **arr);
char	*find_command_path(char *cmd, char **envp);

/*==============================*/
/*	CORE EXECUTION		*/
/*==============================*/
void	execute_command(char **cmd_args, char **envp);
void	child_process_1(t_pipex *px, char *cmd);
void	child_process_2(t_pipex *px, char *cmd);

/*==============================*/
/*	MAIN ENTRYPOINT		*/
/*==============================*/
int		pipex(t_pipex *px, char **argv);
int		main(int argc, char **argv, char **envp);

#endif
