#include "so_long.h"

void validation(int argc, char **argv)
{
    if (argc == 2)
    {
        if (check_format(argv[1]) || !read_map(argv[1]))
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
    if (len > ext && ft_strcmp(str + len - ext, extension) == 0 && str[ext + 1] == '\0')
        return (true);
    return (false);
}

int get_size(char *path)
{
    int fd;
    int flag;
    int map_size;
    char *line;

    fd = open(path, O_RDONLY);
    flag = 1;
    map_size = 0;
    while (flag)
    {
        line = get_next_line(fd);
        if (line == NULL)
            flag = 0;
        else
            map_size++;
    }
    close(fd);
    return (map_size);
}

bool read_map(char *path)
{
    int i;
    int fd;
    int size;
    char *line;
    char **map;

    i = 0;
    size = get_size(path);
    fd = open(path, O_RDONLY);
    map = (char **)malloc(size * sizeof(char *));
    if (!map)
    {
        close(fd);
        return (false);
    }
    while (i < size)
    {
        line = get_next_line(fd);
        map[i] = malloc(ft_strlen(line) + 1);
        ft_strlcpy(map[i], line, ft_strlen(line));
        free(line);
        i++;
    }
    if (!validate_map(size, map))
    {
        free(map);
        close(fd);
        return (false);
    }
    else
    {
        free(map);
        close(fd);
        return (true);
    }
}

bool validate_map(int size, char **map)
{
    int i;
    int j;
    int k;
    int exit;
    int player;
    int collectable;
    char **str;

    i = 0;
    exit = 0;
    collectable = 0;
    player = 0;
    while (i < size)
    {
        j = 0;
        str = ft_split(map[i], '\n');
        if (!str)
        {
            free(str);
            return (NULL);
        }
        while (str[j])
        {
            k = 0;
            while (str[j][k]) {
                if (str[j][k] == 'E')
                    exit++;
                else if (str[j][k] == 'P')
                    player++;
                else if (str[j][k] == 'C')
                    collectable++;
                k++;
            }
            j++;
        }
        free(str);
        i++;
    }
    if (exit == 1 && player == 1 && collectable >= 1)
        return (true);
    return (false);
}