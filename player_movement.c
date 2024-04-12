#include "so_long.h"

void move(t_game *game, int new_x, int new_y)
{
    int current_row;
    int current_col;
    int new_row;
    int new_col;

    current_row = game->player.y / 32;
    current_col = game->player.x / 32;
    if (new_x >= 0 && new_x < game->map_width && new_y >= 0 && new_y < game->map_height)
    {
        game->map[current_row][current_col] = '0';
        new_row = new_y / 32;
        new_col = new_x / 32;
        game->map[new_row][new_col] = 'P';
        game->player.x = new_x;
        game->player.y = new_y;
        mlx_clear_window(game->mlx, game->mlx_win);
        parse_map(game);
    }
}

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        move(game, game->player.x, game->player.y - 32);
    else if (keycode == KEY_A)
        move(game, game->player.x - 32, game->player.y);
    else if (keycode == KEY_S)
        move(game, game->player.x, game->player.y + 32);
    else if (keycode == KEY_D)
        move(game, game->player.x + 32, game->player.y);
}