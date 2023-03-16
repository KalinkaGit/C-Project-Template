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

return_code_t handle_errors(int argc, char *envp[])
{
    if (argc < 2) {
        write(2,
        "Usage: ./my_paint <path/to/save.jpg> [<path/to/load/open.jpg]\n", 63);
        return (CRETURN_FAILURE);
    }
    if (!envp)
        return (CRETURN_FAILURE);
    for (int i = 0; envp[i]; i++) {
        if (my_strncmp(envp[i], "DISPLAY=", 8) == 0)
            return (CRETURN_SUCCESS);
    }
    write(2, "Error: No display found\n", 24);
    return (CRETURN_FAILURE);
}
