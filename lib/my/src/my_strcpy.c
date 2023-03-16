/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-remi.grimault
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
