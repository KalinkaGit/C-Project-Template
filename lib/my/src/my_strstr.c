/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-remi.grimault
** File description:
** my_strstr
*/

/* LOCAL PROTOTYPES */
#include "my.h"

static char *search(char *str, char *to_find, int i, int j)
{
    while (str[i + j] == to_find[j]) {
        j++;
        if (to_find[j] == '\0')
            return (&str[i]);
    }
    return (NULL);
}

char *my_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[j] && search(str, to_find, i, j) != NULL)
            return (search(str, to_find, i, j));
        j = 0;
        i++;
    }

    return (NULL);
}
