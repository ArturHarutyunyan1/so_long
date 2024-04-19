/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:29:34 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/20 01:29:35 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

char	**trim_map(t_game *game, int size)
{
	int		i;
	int		j;
	char	**trimmed_map;

	i = 0;
	j = 0;
	while (i < size && contains_only_whitespace(game->map[i]))
		i++;
	trimmed_map = malloc((size + 1) * sizeof(char *));
	if (!trimmed_map)
		return (NULL);
	while (i < size)
	{
		trimmed_map[j] = malloc(ft_strlen(game->map[i]) + 1);
		ft_strlcpy(trimmed_map[j], game->map[i], ft_strlen(game->map[i]) + 1);
		if (contains_only_whitespace(game->map[i]))
			break ;
		i++;
		j++;
	}
	trimmed_map[j] = NULL;
	return (trimmed_map);
}
