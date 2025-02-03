/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:29:17 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/13 01:29:23 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void check_leaks(void)
{
    system("leaks so_long");
}

int main(int argc, char **argv)
{
    atexit(check_leaks);
    validation(argc, argv);
    init_game(argv[1]);
    return (0);
}