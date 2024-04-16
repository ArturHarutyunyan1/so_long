/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:49:16 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/13 02:53:27 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	validation(int argc, char **argv)
{
	t_game	game;
	t_map	dimensions;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		dimensions = get_dimensions(game.map);
		game.map_height = dimensions.rows;
		game.map_width = dimensions.cols;
		check_format(argv[1]);
		validate_map(argv[1]);
		if (!validate_path(&game, argv[1]))
			ft_exit("Error\nNo valid path\n", &game);
		else if (!surrounded_by_walls(game.map))
			ft_exit("Error\nMap is not surrounded by walls!\n", &game);
		free_matrix(game.map);
	}
	else
		ft_exit("Error\nInvalid number of arguments", NULL);
}

void	check_format(char *path)
{
	int	i;

	i = 0;
	while (path[i] != '.')
		i++;
	if (!(ft_isalnum(path[i - 1]) && path[i + 1] == 'b'
			&& path[i + 2] == 'e' && path[i + 3] == 'r'
			&& path[i + 4] == '\0'))
		ft_exit("Error\nInvalid format\n", NULL);
}

void	check_chars(t_game *game, char c)
{
	if (c == 'E')
		game->player.exit_count++;
	else if (c == 'P')
		game->player.player_count++;
	else if (c == 'C')
		game->player.collectible_count++;
	else if (c == '1' || c == '0')
		return ;
	else
		ft_exit("Error\nInvalid characters\n", game);
}

void	validate_map(char *path)
{
	int		i;
	int		j;
	t_game	game;

	game.player.exit_count = 0;
	game.player.player_count = 0;
	game.player.collectible_count = 0;
	game.player.forbidden_chars = 0;
	i = 0;
	game.map = read_map(path);
	if (!game.map)
		exit(2);
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			check_chars(&game, game.map[i][j]);
			j++;
		}
		i++;
	}
	handle_error_messages(&game, path);
	free_matrix(game.map);
}
