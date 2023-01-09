/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strl
*/

/**
 * @brief Get the length of a string.
 *
 * @param str String to get the length of.
 * @return int Length of the string.
 */
int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);

    return (i);
}
