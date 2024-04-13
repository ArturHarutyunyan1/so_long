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
	if (argc == 2)
	{
		if (!check_format(argv[1]) || !validate_map(argv[1]))
			exit(write(2, "Error\n", 6));
	}
	else
		exit(write(2, "Error\n", 6));
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
		if (line[i] != '1' && line[i] != '0'
			&& line[i] != 'E'
			&& line[i] != 'P'
			&& line[i] != 'C')
			return (false);
		i++;
	}
	return (true);
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
	if (!map)
		return (false);
	while (map[i])
	{
		if (!count_entities(map[i], &exit, &player, &collectable)
			|| !is_rectangular_map(map))
		{
			free_matrix(map);
			return (false);
		}
		i++;
	}
	free_matrix(map);
	return (exit == 1 && player == 1 && collectable >= 1);
}
