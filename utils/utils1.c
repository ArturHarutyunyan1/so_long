/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:27:56 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/13 01:27:57 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_exit(char *str, t_game *game)
{
	ft_printf("Error\nWe've encountered some issues\n%s", str);
	if (game != NULL && game->map != NULL)
		free_matrix(game->map);
	exit(1);
}

bool	is_rectangular_map(char **map)
{
	int		i;
	size_t	length;

	i = 0;
	length = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != length)
			return (false);
		i++;
	}
	return (true);
}

void	handle_error_messages(t_game *game, char *path)
{
	if (game->player.exit_count == 0)
		ft_exit("Error\nNo exit was found\n", game);
	else if (game->player.exit_count > 1)
		ft_exit("Error\nMore than one exit\n", game);
	else if (game->player.player_count == 0)
		ft_exit("Error\nNo player was found\n", game);
	else if (game->player.player_count > 1)
		ft_exit("Error\nMore than one player\n", game);
	else if (game->player.collectible_count == 0)
		ft_exit("Error\nNo collectibles was found\n", game);
	else if (!is_rectangular_map(game->map))
		ft_exit("Error\nMap shape is not rectangular\n", game);
	else if (get_size(path) == -1)
		ft_exit("Error\nMap is empty\n", game);
}

int	exit_game(t_game *game)
{
	free_matrix(game->map);
	destroy_textures(game);
	mlx_destroy_display(game->mlx);
	ft_exit("Error\nGame was closed successfully!\n", game);
	exit(2);
}
