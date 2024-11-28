/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:57:10 by arturhar          #+#    #+#             */
/*   Updated: 2024/11/28 13:41:57 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_textures(t_game *game)
{
	int	len;

	len = 32;
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &len, &len);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &len, &len);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &len, &len);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &len, &len);
	game->textures.collectable = mlx_xpm_file_to_image(game->mlx,
			"textures/collectable.xpm", &len, &len);
	game->textures.semi = mlx_xpm_file_to_image(game->mlx,
			"textures/player1.xpm", &len, &len);
	game->textures.closed = mlx_xpm_file_to_image(game->mlx,
			"textures/player2.xpm", &len, &len);
	game->textures.up = mlx_xpm_file_to_image(game->mlx,
			"textures/up.xpm", &len, &len);
	game->textures.semi_up = mlx_xpm_file_to_image(game->mlx,
			"textures/semi-up.xpm", &len, &len);
	game->textures.down = mlx_xpm_file_to_image(game->mlx,
			"textures/down.xpm", &len, &len);
	game->textures.semi_down = mlx_xpm_file_to_image(game->mlx,
			"textures/semi-down.xpm", &len, &len);
	game->textures.left = mlx_xpm_file_to_image(game->mlx,
			"textures/left.xpm", &len, &len);
	game->textures.semi_left = mlx_xpm_file_to_image(game->mlx,
			"textures/semi-left.xpm", &len, &len);
}

void	destroy_textures(t_game *game)
{
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	else if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	else if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	else if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	else if (game->textures.collectable)
		mlx_destroy_image(game->mlx, game->textures.collectable);
}

void *get_sprite(t_game *game)
{
	static int	i;

	i++;
	if (i <= 5)
	{
		if (strcmp(game->player.direction, "right") == 0)
			return (game->textures.player);
		if (strcmp(game->player.direction, "up") == 0)
			return (game->textures.up);
		if (strcmp(game->player.direction, "down") == 0)
			return (game->textures.down);
		if (strcmp(game->player.direction, "left") == 0)
			return (game->textures.left);
	}
	if (i <= 10)
	{
		if (strcmp(game->player.direction, "right") == 0)
			return (game->textures.semi);
		if (strcmp(game->player.direction, "up") == 0)
			return(game->textures.semi_up);
		if (strcmp(game->player.direction, "down") == 0)
			return (game->textures.semi_down);
		if (strcmp(game->player.direction, "left") == 0)
			return (game->textures.semi_left);
	}
	if (i <= 15)
		return (game->textures.closed);
	if (i <= 20)
	{
		if (strcmp(game->player.direction, "right") == 0)
			return(game->textures.semi);
		if (strcmp(game->player.direction, "up") == 0)
			return(game->textures.semi_up);
		if (strcmp(game->player.direction, "down") == 0)
			return (game->textures.semi_down);
		if (strcmp(game->player.direction, "left") == 0)
			return (game->textures.semi_left);
	}
	if (i > 20)
		i = 0;
	if (strcmp(game->player.direction, "right") == 0)
		return (game->textures.player);
	if (strcmp(game->player.direction, "up") == 0)
		return (game->textures.up);
	if (strcmp(game->player.direction, "down") == 0)
		return (game->textures.down);
	if (strcmp(game->player.direction, "left") == 0)
		return (game->textures.left);
	return (game->textures.player);

}


void	draw(t_game *game, int x, int y, char c)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.floor, x, y);
 	else if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.wall, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.exit, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			get_sprite(game), x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.collectable, x, y);
}
