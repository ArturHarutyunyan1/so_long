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
    int map_width;
    int map_height;
    t_player player;
}t_game;


#endif