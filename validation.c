/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:49:16 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/13 01:49:17 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	validation(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!check_format(argv[1]) || !validate_map(argv[1]))
			exit(write(2, "Invalid map!\n", 12));
	}
	else
		exit(write(2, "Invalid number of arguments!\n", 30));
}

bool	check_format(char *path)
{
	int	i;

	i = 0;
	while (path[i] != '.')
		i++;
	if (ft_isalnum(path[i - 1]) && path[i + 1] == 'b'
		&& path[i + 2] == 'e' && path[i + 3] == 'r'
		&& path[i + 4] == '\0')
		return (true);
	return (false);
}

bool	count_entities(char *line, int *exit, int *player, int *collectable)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			(*exit)++;
		else if (line[i] == 'P')
			(*player)++;
		else if (line[i] == 'C')
			(*collectable)++;
		i++;
	}
}

bool	validate_map(char *path)
{
	int		i;
	int		exit;
	int		player;
	int		collectable;
	char	**map;

	i = 0;
	exit = 0;
	player = 0;
	collectable = 0;
	map = read_map(path);
	while (map[i])
	{
		count_entities(map[i], &exit, &player, &collectable);
		i++;
	}
	free_matrix(map);
	return (exit == 1 && player == 1 && collectable >= 1);
}
