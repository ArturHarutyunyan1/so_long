/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:15:34 by arturhar          #+#    #+#             */
/*   Updated: 2024/11/26 21:21:29 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	update_state(t_game *game, int new_x, int new_y)
{
	int	current_row;
	int	current_col;
	int	new_row;
	int	new_col;

	current_row = game->player.y / 32;
	current_col = game->player.x / 32;
	new_row = new_y / 32;
	new_col = new_x / 32;
	if (game->map[new_row][new_col] == 'C')
		game->collected++;
	game->map[current_row][current_col] = '0';
	game->map[new_row][new_col] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
	parse_map(game);
	ft_printf("Moves: %d\n", game->moves++);
	
}

void	do_move(t_game *game, int new_x, int new_y)
{
	int	moved;
	int	x;
	int	y;

	moved = 0;
	if (game->player.x != new_x || game->player.y != new_y)
		moved = 1;
	x = game->player.x;
	y = game->player.y;
	update_state(game, new_x, new_y);
	if (game->player.on_exit == 1 && moved)
	{
		game->player.on_exit = 0;
		game->map[y / 32][x / 32] = 'E';
		parse_map(game);
	}
}

void	move(t_game *game, int new_x, int new_y)
{
	if (new_x >= 0 && new_x < game->map_width
		&& new_y >= 0 && new_y < game->map_height
		&& (game->map[new_y / 32][new_x / 32] != '1'))
	{
		if (game->map[new_y / 32][new_x / 32] == 'E')
		{
			if (game->collected != game->collectables)
			{
				do_move(game, new_x, new_y);
				game->player.on_exit = 1;
				return ;
			}
			else if (game->collected == game->collectables)
			{
				ft_printf("You win!!!\n");
				free_matrix(game->map);
				destroy_textures(game);
				exit(0);
			}
		}
		else if (game->map[new_y / 32][new_x / 32] == 'G')
		{
			ft_printf("You Lose :(\n");
			free_matrix(game->map);
			destroy_textures(game);
			exit(0);
		}
		do_move(game, new_x, new_y);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
	{
		game->player.direction = "up";
		move(game, game->player.x, game->player.y - 32);
	}
	else if (keycode == KEY_A)
	{
		game->player.direction = "left";
		move(game, game->player.x - 32, game->player.y);
	}
	else if (keycode == KEY_S)
	{
		game->player.direction = "down";
		move(game, game->player.x, game->player.y + 32);
	}
	else if (keycode == KEY_D)
	{
		game->player.direction = "right";
		move(game, game->player.x + 32, game->player.y);
	}
	return (0);
}
