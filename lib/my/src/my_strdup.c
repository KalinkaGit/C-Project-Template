/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-remi.grimault
** File description:
** my_strdup
*/

/* LOCAL INCLUDES */
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int i = 0;

    if (src == NULL)
        return (NULL);
    for (; src[i] != '\0'; i++);
    dest = malloc(sizeof(char) * (i + 1));
    if (dest == NULL) return (NULL);
    for (int j = 0; j < i; j++)
        dest[j] = src[j];
    dest[i] = '\0';
    return (dest);
}
