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
bool read_map(char *path);
int get_size(char *path);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
bool validate_map(int size, char **map);
char	**ft_split(char const *s, char c);
void create_window(char *path);

#endif