NAME		= pipex

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= srcs
INC_DIR		= includes
LIBFTDIR	= libft
OBJ_DIR		= objs

PIPEX_SRCS	= execute_command.c pipe_process.c ft_strcpy.c ft_strcat.c main.c
LIBFT_SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		  ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		  ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		  ft_toupper.c ft_printf.c ft_printf_utils.c get_next_line.c

PIPEX_SRCS_WITH_PATH	= $(addprefix $(SRC_DIR)/, $(PIPEX_SRCS))
LIBFT_SRCS_WITH_PATH	= $(addprefix $(LIBFTDIR)/, $(LIBFT_SRCS))
ALL_SRCS		= $(PIPEX_SRCS_WITH_PATH) $(LIBFT_SRCS_WITH_PATH)

PIPEX_OBJS		= $(addprefix $(OBJ_DIR)/, $(PIPEX_SRCS:.c=.o))
LIBFT_OBJS		= $(addprefix $(OBJ_DIR)/, $(LIBFT_SRCS:.c=.o))
ALL_OBJS		= $(PIPEX_OBJS) $(LIBFT_OBJS)

INCLUDES	= -I$(INC_DIR) -I$(LIBFTDIR)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJ_DIR)/%.o: $(LIBFTDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(NAME): $(ALL_OBJS)
	$(CC) $(CFLAGS) $(ALL_OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
