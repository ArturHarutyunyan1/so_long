#include "so_long.h"

bool validation(int argc, char **argv)
{
    if (argc == 2)
    {
        if (check_format(argv[1]))
            printf("Everything is cool\n");
        else
            printf("Something is wrong\n");
    }
}

bool check_format(char *str)
{
    char *extenstion;
    int len;
    int ext;

    extenstion = ".ber";
    len = ft_strlen(str);
    ext = ft_strlen(extenstion);
    if (len > ext && ft_strcmp(str + len - ext, extenstion) == 0 && str[ext + 1] == '\0')
        return (true);
    return (false);
}
