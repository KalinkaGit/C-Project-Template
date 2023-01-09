/*
** EPITECH PROJECT, 2023
** cat_str_int
** File description:
** cat_str_int
*/

#include "my.h"

char *cat_str_int(char *str, int nb)
{
    int len = my_get_nbr_len(nb);
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + len + 1));
    int i;

    for (i = 0; str[i] != '\0'; i++)
        new_str[i] = str[i];

    if (nb == 0) {
        new_str[i] = '0';
        i++;
    }
    for (int j = 0; j < len; j++) {
        new_str[i] = (nb / my_compute_power_rec(10, len - j - 1)) + 48;
        nb = nb % my_compute_power_rec(10, len - j - 1);
        i++;
    }

    new_str[i] = '\0';

    return (new_str);
}
