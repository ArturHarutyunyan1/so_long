/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:31:24 by arturhar          #+#    #+#             */
/*   Updated: 2025/02/03 17:33:36 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ppart2(t_game *game)
{
	if (game->textures.down)
		mlx_destroy_image(game->mlx, game->textures.down);
	if (game->textures.left)
		mlx_destroy_image(game->mlx, game->textures.left);
	if (game->textures.semi)
		mlx_destroy_image(game->mlx, game->textures.semi);
	if (game->textures.semi_down)
		mlx_destroy_image(game->mlx, game->textures.semi_down);
	if (game->textures.semi_left)
		mlx_destroy_image(game->mlx, game->textures.semi_left);
	if (game->textures.semi_up)
		mlx_destroy_image(game->mlx, game->textures.semi_up);
	if (game->textures.up)
		mlx_destroy_image(game->mlx, game->textures.up);
	if (game->textures.enemy)
		mlx_destroy_image(game->mlx, game->textures.enemy);
}

void	part2(t_game *game)
{
	int	len;

	len = 32;
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
	game->textures.enemy = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm", &len, &len);
}

int	get_sprite_index(void)
{
	static int	i;

	i++;
	if (i > 20)
		i = 0;
	return (i);
}

void	*get_direction_texture(t_game *game, const char *direction)
{
	if (ft_strcmp(direction, "right") == 0)
		return (game->textures.player);
	if (ft_strcmp(direction, "up") == 0)
		return (game->textures.up);
	if (ft_strcmp(direction, "down") == 0)
		return (game->textures.down);
	if (ft_strcmp(direction, "left") == 0)
		return (game->textures.left);
	return (game->textures.player);
}

void	setup_game(t_game *game, char *path)
{
	t_map	map;

	game->map = read_map(path);
	map = get_dimensions(game->map);
	game->map_width = map.cols * 32;
	game->map_height = map.rows * 32 + 10;
	game->collectables = get_counts(game->map).collectables;
	game->collected = 0;
	game->moves = 1;
	game->x = 0;
	game->y = 0;
	game->player.on_exit = 0;
	game->player.direction = "right";
	game->mlx = mlx_init();
}
