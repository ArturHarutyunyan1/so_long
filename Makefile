NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-arch x86_64
SRC_DIR = src
UTIL_DIR = utils
MLX_DIR = mlx
SRCS = $(SRC_DIR)/graphical_utils.c \
	   $(SRC_DIR)/init_game.c \
	   $(SRC_DIR)/main.c \
	   $(SRC_DIR)/player_movement.c \
	   $(SRC_DIR)/validation.c \
	   $(UTIL_DIR)/ft_calloc.c \
	   $(UTIL_DIR)/ft_isalnum.c \
	   $(UTIL_DIR)/ft_isalpha.c \
	   $(UTIL_DIR)/ft_isdigit.c \
	   $(UTIL_DIR)/ft_isspace.c \
	   $(UTIL_DIR)/ft_memmove.c \
	   $(UTIL_DIR)/ft_memset.c \
	   $(UTIL_DIR)/ft_print_hex.c \
	   $(UTIL_DIR)/ft_printf.c \
	   $(UTIL_DIR)/ft_printf_utils.c \
	   $(UTIL_DIR)/ft_format_parser.c \
	   $(UTIL_DIR)/ft_itoa.c \
	   $(UTIL_DIR)/ft_strchr.c \
	   $(UTIL_DIR)/ft_strdup.c \
	   $(UTIL_DIR)/ft_strjoin.c \
	   $(UTIL_DIR)/ft_strlcpy.c \
	   $(UTIL_DIR)/ft_strlen.c \
	   $(UTIL_DIR)/get_next_line.c \
	   $(UTIL_DIR)/utils.c \
	   $(UTIL_DIR)/utils1.c \
	   $(UTIL_DIR)/utils2.c \
	   $(UTIL_DIR)/utils3.c \
	   $(UTIL_DIR)/ft_strtrim.c \
	   $(UTIL_DIR)/ft_strcmp.c

OBJS = $(SRCS:.c=.o)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) -L$(MLX_DIR) -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $(NAME)
all: $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

# .PHONY all re clean fclean