#include "so_long.h"

void validation(int argc, char **argv)
{
    t_game game;

    if (argc == 2)
    {
        if (check_format(argv[1]) || !validate_map(&game,argv[1]))
            exit(write(2, "Invalid Map!\n", 13));
    }
    else
        exit(write(2, "Invalid number of arguments!\n", 30));
}

bool check_format(char *str)
{
    char *extension;
    int len;
    int ext;

    extension = ".ber";
    len = ft_strlen(str);
    ext = ft_strlen(extension);
    if (len > ext && ft_strcmp(str + len - ext, extension) == 0 && str[len - ext - 1] == '.')
        return (true);
    return (false);
}

int get_size(char *path)
{
    int fd;
    int size = 0;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        exit(write(2, "Invalid Map!\n", 13));
    while (get_next_line(fd) > 0)
    {
        size++;
    }
    close(fd);
    return size;
}

t_game read_map(char *path)
{
    t_game game;
    int fd;
    int row;
    int size;
    char *line;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        exit(write(2, "Invalid Map!\n", 13));
    row = 0;
    size = get_size(path);
    game.map = (char **)malloc((size + 1) * sizeof(char *));
    if (game.map == NULL)
        exit(write(2, "Invalid Map!\n", 13));
    while (get_next_line(fd) > 0)
    {
        line = get_next_line(fd);
        game.map[row] = ft_strdup(line);
        if (game.map[row] == NULL)
            exit(write(2, "Invalid Map!\n", 13));
        row++;
    }
    close(fd);
    game.map[row] = NULL;
    return (game);
}

bool validate_map(t_game *game, char *path)
{
    int i;
    int j;
    int exit;
    int player;
    int collectable;
    char **map;

    i = 0;
    exit = 0;
    player = 0;
    collectable = 0;
    *game = read_map(path);
    map = game->map;
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