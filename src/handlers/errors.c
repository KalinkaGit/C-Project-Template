/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** errs
*/

/* SYSTEM INCLUDES */
#include <unistd.h>

/* LOCAL INCLUDES */
#include "constants.h"
#include "handlers.h"
#include "my.h"

char *handle_errors(int argc, char *envp[])
{
    if (argc < 2) {
        write(2,
        "Usage: ./my_paint <path/to/save.jpg> [<path/to/load/open.jpg]\n", 63);
        return (NULL);
    }
    if (!envp)
        return (NULL);
    char *login = NULL;
    for (int i = 0; envp[i]; i++) {
        if (my_strncmp(envp[i], "USER=", 5) == 0)
            login = envp[i] + 5;
    }
    if (login == NULL)
        login = "Unknown";
    for (int i = 0; envp[i]; i++) {
        if (my_strncmp(envp[i], "DISPLAY=", 8) == 0)
            return (login);
    }
    write(2, "Error: No display found\n", 24);
    return (NULL);
}
