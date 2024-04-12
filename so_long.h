#ifndef SO_LONG_H
#define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#define KEY_W XK_w
#define KEY_A XK_a
#define KEY_S XK_s
#define KEY_D XK_d

#include "libft/libft.h"
#include <stdbool.h>
#include <mlx.h>
#include <X11/keysym.h>


typedef struct s_data
{
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
    int width;
    int height;
}t_data;

typedef struct s_map
{
    int rows;
    int cols;
}t_map;

typedef struct s_player
{
    int x;
    int y;
}t_player;

typedef struct s_game
{
    void *mlx;
    void *mlx_win;
    char **map;
    int map_width;
    int map_height;
    t_player player;
}t_game;

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t items, size_t size);
size_t	ft_strlen(const char *str);
int	ft_isalnum(int c);
char	*ft_strdup(const char *src);
int	ft_isalpha(int c);
void	*ft_memmove(void *dest, const void *src, size_t n);

void validation(int argc, char **argv);
bool check_format(char *path);

#endif