#include "so_long.h"

int attempt_move(t_game *game, int new_x, int new_y)
{
    int success;

    success = 0;
    if (new_x >= 0 && new_x < game->map_width && new_y >= 0 && new_y < game->map_height)
    {
        if (game->map[new_y / 32][new_x / 32] != '1' && game->map[new_y / 32][new_x / 32] != 'E')
            success = 1;
    }
    return (success);
}

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
        if (game->map[new_y / 32][new_x / 32] != '1' && game->map[new_y / 32][new_x / 32] != 'E')
        {
            if (game->map[new_y / 32][new_x / 32] == 'C')
                game->collected++;
            game->map[current_row][current_col] = '0';
            new_row = new_y / 32;
            new_col = new_x / 32;
            game->map[new_row][new_col] = 'P';
            game->player.x = new_x;
            game->player.y = new_y;
            parse_map(game);
            write(1, "Moves: ", 7);
            ft_putnbr(game->moves++);
            write(1, "\n", 1);
        }
    }
    if (game->collected == game->collectables)
    {
        if (game->map[new_y / 32][new_x / 32] == 'E')
            exit(write(1, "You Win!\n", 9));
    }
}

int key_press(int keycode, t_game *game)
{
    static int counter;

    if (keycode == KEY_ESC)
        exit_game(game);
    else if (keycode == KEY_W)
        move(game, game->player.x, game->player.y - 32);
    else if (keycode == KEY_A)
        move(game, game->player.x - 32, game->player.y);
    else if (keycode == KEY_S)
        move(game, game->player.x, game->player.y + 32);
    else if (keycode == KEY_D)
        move(game, game->player.x + 32, game->player.y);
    return (0);
}