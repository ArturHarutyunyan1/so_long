#include "../include/so_long.h"

bool is_valid_path(t_game *game, int row, int col)
{
    if (row < 0 || col < 0 || row >= game->map_height || col >= game->map_width || game->map[row][col] == '1' || game->map[row][col] == 'v')
        return (false);
    if (game->map[row][col] == 'E')
        return (true);
    game->map[row][col] = 'v';
    return (is_valid_path(game, row + 1, col) ||
            is_valid_path(game, row - 1, col) ||
            is_valid_path(game, row, col + 1) ||
            is_valid_path(game, row, col - 1));
}

bool validate_path(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == 'P')
            {
                game->player.x = i;
                game->player.y = j;
                break;
            }
            j++;
        }
        i++;
    }
    return (is_valid_path(game, game->player.x, game->player.y));
}