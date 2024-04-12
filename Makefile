NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
UTIL_DIR = utils
MLX_FLAGS = -lmlx

SRCS = $(SRC_DIR)/graphical_utils.c \
	   $(SRC_DIR)/init_game.c \
	   $(SRC_DIR)/main.c \
	   $(SRC_DIR)/player_movement.c \
	   $(SRC_DIR)/validation.c \
	   $(UTIL_DIR)/ft_calloc.c \
	   $(UTIL_DIR)/ft_isalnum.c \
	   $(UTIL_DIR)/ft_isalpha.c \
	   $(UTIL_DIR)/ft_isdigit.c \
	   $(UTIL_DIR)/ft_memmove.c \
	   $(UTIL_DIR)/ft_memset.c \
	   $(UTIL_DIR)/ft_strchr.c \
	   $(UTIL_DIR)/ft_strdup.c \
	   $(UTIL_DIR)/ft_strjoin.c \
	   $(UTIL_DIR)/ft_strlcpy.c \
	   $(UTIL_DIR)/ft_strlen.c \
	   $(UTIL_DIR)/get_next_line.c \
	   $(UTIL_DIR)/utils.c \
	   $(UTIL_DIR)/utils1.c

OBJS = $(SRCS:.c=.o)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) -lmlx -lXext -lX11
all: $(NAME)
clean:
	$(RM) $(NAME) $(OBJS)
fclean:
	$(RM) $(NAME)
re: fclean all