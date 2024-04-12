#include "so_long.h"

void validation(int argc, char **argv)
{
    if (argc == 2)
    {
        if (!check_format(argv[1]))
            exit(write(2, "Invalid map!\n", 12));
    }
    else
        perror("Invalid number of arguments!");
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