/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:42:05 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/13 00:44:06 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	parse_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->y = 0;
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
}

void	init_game(char *path)
{
	t_game	game;
	t_map	map;

	game.map = read_map(path);
	map = get_dimensions(game.map);
	game.map_width = map.cols * 32;
	game.map_height = map.rows * 32;
	game.collectables = get_counts(game.map).collectables;
	game.collected = 0;
	game.moves = 1;
	game.x = 0;
	game.y = 0;
	game.player.on_exit = 0;
	game.mlx = mlx_init();
	init_textures(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.map_width,
			game.map_height, "So Long");
	parse_map(&game);
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.mlx_win, DestroyNotify,
		StructureNotifyMask, exit_game, &game);
	mlx_loop(game.mlx);
	free_matrix(game.map);
	destroy_textures(&game);
}
