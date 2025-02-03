/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:42:05 by arturhar          #+#    #+#             */
/*   Updated: 2025/02/03 17:23:31 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	moves(t_game *game)
{
	char	*counter;

	counter = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->mlx_win, 0, 10, 0xFFFFFF, "Moves");
	mlx_string_put(game->mlx, game->mlx_win, 50, 10, 0xFFFFFF, counter);
	free(counter);
}

static void	parse_map_row(t_game *game, int i)
{
	int	j;

	j = 0;
	game->x = 0;
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
}

void	parse_map(t_game *game)
{
	int	i;

	i = 0;
	game->y = 10;
	while (game->map[i])
	{
		parse_map_row(game, i);
		game->y += 32;
		i++;
	}
	moves(game);
}

int	game_loop(t_game *game)
{
	static int	frame_counter;

	frame_counter = 0;
	mlx_clear_window(game->mlx, game->mlx_win);
	frame_counter++;
	if (frame_counter >= 10)
	{
		frame_counter = 0;
		get_sprite(game);
	}
	parse_map(game);
	return (0);
}

void	init_game(char *path)
{
	t_game	game;

	setup_game(&game, path);
	init_textures(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.map_width,
			game.map_height, "So Long");
	parse_map(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx_win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	free_matrix(game.map);
	destroy_textures(&game);
}
