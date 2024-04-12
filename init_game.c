#include "so_long.h"

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
        game.collectables = get_counts(game.map).collectables;
        game.collected = 0;
        game.moves = 1;
        game.mlx = mlx_init();
        init_textures(&game);
        game.mlx_win = mlx_new_window(game.mlx, game.map_width, game.map_height, "So Long");
        parse_map(&game);
        mlx_hook(game.mlx_win, KeyPress, KeyPressMask, key_press, &game);
        mlx_hook(game.mlx_win, DestroyNotify, StructureNotifyMask, exit_game, &game);
        mlx_loop(game.mlx);
        free_matrix(game.map);
        destroy_textures(&game);
}