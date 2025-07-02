NAME = pipex

SRCS = srcs/main.c srcs/execute.c srcs/files.c srcs/process.c srcs/utils.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes -Ilibft
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
