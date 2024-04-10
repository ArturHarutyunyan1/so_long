#include "so_long.h"

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i] == str2[i] && str1[i])
        i++;
    return (str1[i] - str2[i]);
}