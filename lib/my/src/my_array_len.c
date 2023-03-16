/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-remi.grimault
** File description:
** my_array_len
*/

/* LOCAL INCLUDES */
#include "my.h"

int my_array_len(char **array)
{
    int i = 0;

    if (array == NULL) return (0);
    for (; array[i] != NULL; i++);

    return (i);
}
