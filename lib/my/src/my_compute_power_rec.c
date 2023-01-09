/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

/**
 * @brief Compute the power of a number.
 *
 * @param nb Number.
 * @param p Power.
 * @return int Result.
 */
int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    return (nb * my_compute_power_rec(nb, p - 1));
}
