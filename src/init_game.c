/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:42:05 by arturhar          #+#    #+#             */
/*   Updated: 2024/11/26 21:24:22 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void parse_map(t_game *game)
{
    int i, j;

    i = 0;
    game->y = 10;
    while (game->map[i])
    {
        game->x = 0;
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player.x = game->x;
                game->player.y = game->y;
                // Use animated sprite for player
                draw(game, game->player.x, game->player.y, 'P');
            }
            else
                draw(game, game->x, game->y, game->map[i][j]);
            game->x += 32;
            j++;
        }
        game->y += 32;
        i++;
    }
	mlx_string_put(game->mlx, game->mlx_win, 0, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->mlx_win, 50, 10, 0xFFFFFF, ft_itoa(game->moves));
}


int game_loop(t_game *game)
{
    
    static int frame_counter = 0;
    
    mlx_clear_window(game->mlx, game->mlx_win); // Clear the window before redrawing
    
    // Increment the frame counter
    frame_counter++;

    // Update animation every few frames (e.g., every 10 frames)
    if (frame_counter >= 10)
    {
        frame_counter = 0; // Reset counter
        get_sprite(game);  // Update the player's sprite
    }

    parse_map(game); // Redraw the entire map, including the player

    return (0);
}



void	init_game(char *path)
{
	t_game	game;
	t_map	map;

	game.map = read_map(path);
	map = get_dimensions(game.map);
	game.map_width = map.cols * 32;
	game.map_height = map.rows * 32 + 10;
	game.collectables = get_counts(game.map).collectables;
	game.collected = 0;
	game.moves = 1;
	game.x = 0;
	game.y = 0;
	game.player.on_exit = 0;
    game.player.direction = "right";
	game.mlx = mlx_init();
	mlx_loop_hook(game.mlx, game_loop, &game);
	init_textures(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.map_width,
			game.map_height, "So Long");
	parse_map(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx_win, 17,
		0, exit_game, &game);
	mlx_loop(game.mlx);
	free_matrix(game.map);
	destroy_textures(&game);
}
