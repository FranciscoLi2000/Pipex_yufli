# ========= CONFIG ============
NAME		= pipex

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= execute_command.c ft_putstr_fd.c ft_strlen.c pipex.c \
		find_command_path.c ft_split.c ft_strncmp.c free_str_array.c \
		ft_strdup.c ft_substr.c ft_putchar_fd.c ft_strjoin.c main.c

OBJS		= $(SRCS:.c=.o)

INCLUDES	= pipex.h

# ========= RULES =============
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

# ========= CLEANING ==========
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ========= BONUS (可选) =======
# debug:
#	$(MAKE) CFLAGS="-g3 -fsanitize=address -Wall -Wextra -Werror" re

# ========= PHONY RULES ========
.PHONY: all clean fclean re
