/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:57:10 by arturhar          #+#    #+#             */
/*   Updated: 2025/02/03 17:11:02 by arturhar         ###   ########.fr       */
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
	part2(game);
}

void	destroy_textures(t_game *game)
{
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	if (game->textures.collectable)
		mlx_destroy_image(game->mlx, game->textures.collectable);
	ppart2(game);
}

void	*get_sprite(t_game *game)
{
	int	i;

	i = get_sprite_index();
	if (i <= 5)
		return (get_direction_texture(game, game->player.direction));
	if (i <= 10)
	{
		if (ft_strcmp(game->player.direction, "right") == 0)
			return (game->textures.semi);
		if (ft_strcmp(game->player.direction, "up") == 0)
			return (game->textures.semi_up);
		if (ft_strcmp(game->player.direction, "down") == 0)
			return (game->textures.semi_down);
		if (ft_strcmp(game->player.direction, "left") == 0)
			return (game->textures.semi_left);
	}
	if (i <= 15)
		return (game->textures.closed);
	if (i <= 20)
		return (get_direction_texture(game, game->player.direction));
	return (get_direction_texture(game, game->player.direction));
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
	else if (c == 'G')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.enemy, x, y);
}
