#include "so_long.h"

int ft_putchar(int c)
{
    write(1, &c, 1);
}

int ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int exit_game(t_game *game)
{
    free_matrix(game->map);
    destroy_textures(game);
    mlx_destroy_display(game->mlx);
    exit(write(1, "Game was closed successfully!\n", 31));
}