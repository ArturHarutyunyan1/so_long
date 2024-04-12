#include "so_long.h"

void validation(int argc, char **argv)
{
    if (argc == 2)
    {
        if (!check_format(argv[1]) || !validate_map(argv[1]))
            exit(write(2, "Invalid map!\n", 12));
    }
    else
        exit(write(2, "Invalid number of arguments!\n", 30));
}

bool check_format(char *path)
{
    int i;

    i = 0;
    while (path[i] != '.')
        i++;
    if (ft_isalnum(path[i - 1]) && path[i + 1] == 'b' && path[i + 2] == 'e' && path[i + 3] == 'r' && path[i + 4] == '\0')
        return (true);
    return (false);
}

bool validate_map(char *path)
{
    int i;
    int j;
    int exit;
    int player;
    int collectable;
    char **map;

    map = read_map(path);
    i = 0;
    exit = 0;
    player = 0;
    collectable = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                exit++;
            else if (map[i][j] == 'P')
                player++;
            else if (map[i][j] == 'C')
                collectable++;
            j++;
        }
        i++;
    }
    if (exit == 1 && player == 1 && collectable >= 1)
        return (true);
    return (false);
}