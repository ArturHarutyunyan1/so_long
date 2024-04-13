/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:25:16 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/13 01:25:22 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	get_size(char *path)
{
	int		fd;
	int		flag;
	int		map_size;
	char	*line;

	fd = open(path, O_RDONLY);
	flag = 1;
	map_size = 0;
	while (flag)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (map_size == 0)
				return (-1);
			flag = 0;
		}
		else
			map_size++;
		free(line);
	}
	close(fd);
	return (map_size);
}

char	**read_map(char *path)
{
	int		i;
	int		fd;
	int		size;
	char	*line;
	char	**map;

	i = 0;
	size = get_size(path);
	fd = open(path, O_RDONLY);
	map = (char **)malloc((size + 1) * sizeof(char *));
	if (!map)
		return (false);
	while (i < size)
	{
		line = get_next_line(fd);
		map[i] = malloc(ft_strlen(line) + 1);
		ft_strlcpy(map[i], line, ft_strlen(line));
		free(line);
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

t_map	get_dimensions(char **str)
{
	int		i;
	int		len;
	t_map	map;

	i = 0;
	map.rows = 0;
	map.cols = 0;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (len > map.cols)
			map.cols = len;
		map.rows++;
		i++;
	}
	return (map);
}

t_game	get_counts(char **str)
{
	int		i;
	int		j;
	t_game	game;

	i = 0;
	game.collectables = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				game.collectables++;
			j++;
		}
		i++;
	}
	return (game);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
