NAME		= pipex

SRC		= \
		execute_command.c ft_putchar_fd.c ft_strdup.c ft_strncmp.c \
		pipex.c find_command_path.c ft_putstr_fd.c ft_strjoin.c \
		ft_substr.c free_str_array.c ft_split.c ft_strlen.c \
		main.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRE		= ./srcs/
HEAD		= ./includes/

RM		= rm -f

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
