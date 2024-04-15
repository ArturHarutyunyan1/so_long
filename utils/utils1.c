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
	if (game->map[0])
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

int	is_wall(t_game *game, int x, int y)
{
	return (x < 0 || y < 0
		|| x >= game->map_height
		|| y >= game->map_width
		|| game->map[x][y] == '1');
}

//void ft_walls(t_game *game)
//{
//    int i;
//    int c;
//    int len;
//
//    i = 0;
//    len = 0;
//    while (game->map[i])
//    {
//        c = 0;
//        len = ft_strlen(game->map[i]);
//        if (game->map[0][c] != '1' || game->map[len - 1][c] != '1')
//            ft_exit("Error\nMap is not surrounded by walls\n");
//        if (game->map[i][0] != '1' || game->map[1])
//        i++;
//    }
//}
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
	ft_printf("Game was closed successfully!\n");
	exit(0);
}
