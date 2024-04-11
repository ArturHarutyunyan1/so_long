#ifndef SO_LONG_H
#define SO_LONG_H

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
    t_player player;
}t_game;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <mlx.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t items, size_t size);
size_t	ft_strlen(const char *str);

bool check_format(char *str);
int ft_strcmp(char *str1, char *str2);
void validation(int argc, char **argv);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	**ft_split(char const *s, char c);
void create_window(char *path);
bool validate_map(t_game *game, char *path);
int get_size(char *path);
char	*ft_strdup(const char *src);
#endif