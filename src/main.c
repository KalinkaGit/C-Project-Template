/*
** EPITECH PROJECT, 2023
** PROJECT NAME
** File description:
** Main
*/

/* SYSTEM INCLUDES */

/* LOCAL INCLUDES */
#include "constants.h"
#include "handlers.h"

int main(int argc, char *argv[])
{
    if (handle_errors(argc, argv) == RETURN_FAILURE)
        return (EXIT_FAILURE);
    if (handle_args(argc, argv) == RETURN_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
