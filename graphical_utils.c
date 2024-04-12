#include "so_long.h"

void init_textures(t_game *game)
{
    int len;

    len = 32;
    game->textures.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &len, &len);
    game->textures.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &len, &len);
    game->textures.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &len, &len);
    game->textures.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &len, &len);
    game->textures.collectable = mlx_xpm_file_to_image(game->mlx, "textures/collectable.xpm", &len, &len);
}

void destroy_textures(t_game *game)
{
    if (game->textures.floor)
        mlx_destroy_image(game->mlx, game->textures.floor);
    else if (game->textures.wall)
        mlx_destroy_image(game->mlx, game->textures.wall);
    else if (game->textures.exit)
        mlx_destroy_image(game->mlx, game->textures.exit);
    else if (game->textures.player)
        mlx_destroy_image(game->mlx, game->textures.player);
    else if (game->textures.collectable)
        mlx_destroy_image(game->mlx, game->textures.collectable);
}

void draw(t_game *game, int x, int y, char c)
{
    if (c == '0')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.floor, x, y);
    else if (c == '1')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.wall, x, y);
    else if (c == 'E')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.exit, x, y);
    else if (c == 'P')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.player, x, y);
    else if (c == 'C')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.collectable, x, y);
}
