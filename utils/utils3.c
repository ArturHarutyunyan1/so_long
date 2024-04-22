/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:29:34 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/21 05:27:14 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	get_i_pos(t_game *game, int size)
{
	int	i;

	i = 0;
	while (i < size && contains_only_whitespace(game->map[i]))
		i++;
	return (i);
}

int	get_j_pos(t_game *game, int size)
{
	int	j;

	j = get_i_pos(game, size);
	while (j < size && !contains_only_whitespace(game->map[j]))
		j++;
	return (j);
}

char	**trim_map(t_game *game, int size)
{
	int		i;
	int		j;
	int		k;
	t_map	map;

	map = get_dimensions(game->map);
	i = get_i_pos(game, size);
	j = get_j_pos(game, size);
	k = 0;
	if (map.rows > j - i)
		ft_exit("Error\nMap has empty lines\n", game);
	game->trim = malloc((j - i + 1) * sizeof(char *));
	if (!game->trim)
		return (NULL);
	while (i < j)
	{
		game->trim[k] = malloc(ft_strlen(game->map[i]) + 1);
		ft_strlcpy(game->trim[k], game->map[i], ft_strlen(game->map[i]) + 1);
		i++;
		k++;
	}
	free_matrix(game->map);
	game->trim[k] = NULL;
	return (game->trim);
}
