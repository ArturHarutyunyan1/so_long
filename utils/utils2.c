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

int collectible_count(t_game *game, int row, int col)
{
    int count;
    count = 0;
    if (row < 0 || col < 0 || row >= game->map_height || col >= game->map_width || game->map[row][col] == '1' || game->map[row][col] == 'v')
        return (false);
    if (game->map[row][col] == 'C')
        count++;
    game->map[row][col] = 'v';
    count += collectible_count(game, row + 1, col);
    count += collectible_count(game, row - 1, col);
    count += collectible_count(game, row, col + 1);
    count += collectible_count(game, row, col - 1);
    return (count);
}

bool validate_path(t_game *game, char *path)
{
    int i;
    int j;
    int count;

    i = 0;
    game->player.collectible_count = get_counts(game->map).collectables;
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
    count = collectible_count(game, game->player.x, game->player.y);
    game->map = read_map(path);
    return (is_valid_path(game, game->player.x, game->player.y) && (count == game->player.collectible_count));
}