/*
** EPITECH PROJECT, 2023
** my_memcpy
** File description:
** my_memcpy
*/

#include "my.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    for (size_t i = 0; i < n; i++)
        d[i] = s[i];
    return dest;
}
