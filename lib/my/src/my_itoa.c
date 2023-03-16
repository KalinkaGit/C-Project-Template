/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-remi.grimault
** File description:
** my_itoa
*/

/* SYSTEM INCLUDES */
#include <stdlib.h>

/* LOCAL INCLUDES */
#include "my.h"

char *my_itoa(int number)
{
    int size = 0;
    int tmp = number;
    while (tmp != 0) {
        tmp /= 10;
        size++;
    }
    char *str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        return (NULL);
    str[size] = '\0';
    for (int i = size - 1; i >= 0; i--) {
        str[i] = number % 10 + '0';
        number /= 10;
    }
    return (str);
}
