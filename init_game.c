#include "so_long.h"

void draw(t_game *game,int x, int y, int c)
{
    t_data img;

    if (c == '2')
        img.img = mlx_xpm_file_to_image(game->mlx, "textures/floor_eaten.xpm", &img.width, &img.height);
    else if (c == '0')
        img.img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &img.width, &img.height);
    else if (c == '1')
        img.img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &img.width, &img.height);
    else if (c == 'E')
        img.img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &img.width, &img.height);
    else if (c == 'P')
        img.img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &img.width, &img.height);
    else if (c == 'C')
        img.img = mlx_xpm_file_to_image(game->mlx, "textures/collectable.xpm", &img.width, &img.height);
    mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x, y);
}

void parse_map(t_game *game)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    y = 0;
    while (game->map[i])
    {
        x = 0;
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player.x = x;
                game->player.y = y;
                draw(game, game->player.x, game->player.y, 'P');
            }
            else
                draw(game, x, y, game->map[i][j]);
            x += 32;
            j++;
        }
        y += 32;
        i++;
    }
}

void init_game(char *path)
{
    t_game game;
    t_map map;

    game.map = read_map(path);
    map = get_dimensions(game.map);
    game.map_width = map.cols * 32;
    game.map_height = map.rows * 32;
    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, game.map_width, game.map_height, "So Long");
    parse_map(&game);
    mlx_hook(game.mlx_win, KeyPress, KeyPressMask, key_press, &game);
    mlx_loop(game.mlx);
}