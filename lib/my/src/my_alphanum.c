/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-remi.grimault
** File description:
** my_alphanum
*/

/* SYSTEM INCLUDES */
#include <stdbool.h>

/* LOCAL INCLUDES */
#include "my.h"

bool my_alphanum(char *str)
{
    int i = 0;

    if (str == NULL) return (false);
    for (; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9') &&
            str[i] != '/' && str[i] != ':' &&
            str[i] != '_' && str[i] != '.')
            return (false);
    }

    return (true);
}
