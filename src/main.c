/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:29:17 by arturhar          #+#    #+#             */
/*   Updated: 2025/02/03 17:24:43 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"
/*
void check_leaks(void)
 {
     system("leaks so_long");
}
*/

int	main(int argc, char **argv)
{
	validation(argc, argv);
	init_game(argv[1]);
	return (0);
}
