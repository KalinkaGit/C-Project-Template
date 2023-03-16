/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-remi.grimault
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
