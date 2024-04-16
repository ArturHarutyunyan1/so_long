/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:15:34 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/13 01:17:19 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void    do_move(t_game *game, int new_x, int new_y)
{
    int current_row;
    int current_col;
    int new_row;
    int new_col;
    int player_moved;

    player_moved = 0;
    current_row = game->player.y / 32;
    current_col = game->player.x / 32;
    if (game->map[new_y / 32][new_x / 32] == 'C')
        game->collected++;
    game->map[current_row][current_col] = '0';
    new_row = new_y / 32;
    new_col = new_x / 32;
    game->map[new_row][new_col] = 'P';
    if (game->player.x != new_x || game->player.y != new_y)
        player_moved = 1;
    game->player.x = new_x;
    game->player.y = new_y;
    parse_map(game);
    ft_printf("Moves: %d\n", game->moves++);
    if (game->player.on_exit == 1 && player_moved)
    {
        game->player.on_exit = 0;
        game->map[current_row][current_col] = 'E';
        parse_map(game);
    }
}

void    move(t_game *game, int new_x, int new_y)
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
                return;
            }
            else if (game->collected == game->collectables)
                exit_game(game);
        }
        do_move(game, new_x, new_y);
    }
}

int	key_press(int keycode, t_game *game)
{
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
