#include "so_long.h"

static void draw(void *mlx, void *mlx_win, int x, int y, char c)
{
    t_data img;

    if (c == '0')
        img.img = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &img.width, &img.height);
    else if (c == '1')
        img.img = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &img.width, &img.height);
    else if (c == 'P')
        img.img = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &img.width, &img.height);
    else if (c == 'E')
        img.img = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &img.width, &img.height);
    else if (c == 'C')
        img.img = mlx_xpm_file_to_image(mlx, "textures/collectable.xpm", &img.width, &img.height);
    mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
}

static void parse_map(void *mlx, void *mlx_win, char *path)
{
    int i;
    int j;
    int x;
    int y;
    int fd;
    int size;
    char *line;

    i = 0;
    x = 0;
    y = 0;
    size = get_size(path);
    fd = open(path, O_RDONLY);
    while (i < size)
    {
        line = get_next_line(fd);
        j = 0;
        while (line[j])
        {
            draw(mlx, mlx_win, x, y, line[j]);
            x += 32;
            j++;
        }
        y += 32;
        x = 0;
        free (line);
        i++;
    }
    close(fd);
}

void create_window(char *path)
{
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1024, 768, "So Long");
    parse_map(mlx, mlx_win, path);
    mlx_loop(mlx);
}
