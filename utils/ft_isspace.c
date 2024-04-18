#include "../include/so_long.h"

int ft_isspace(int c)
{
    if (c == '\t' || c == '\n' || c == ' ')
        return (1);
    return (0);
}