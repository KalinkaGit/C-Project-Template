/*
** EPITECH PROJECT, 2023
** PROJECT NAME
** File description:
** Header file for handlers used throughout the project.
*/

#ifndef HANDLERS_H_
    #define HANDLERS_H_

    /* LOCAL INCLUDES */
    #include "constants.h"
    #include "paint.h"

    /**
     * @brief Handle errors of the program.
     *
     * @param envp Arguments vector.
     * @return int 0 if handling was successful, -1 otherwise.
     */
    char *handle_errors(int argc, char *envp[]);

    /**
     * @brief Handle the window events.
     *
     * @param paint Paint structure.
     * @return int 0 if handling was successful, -1 otherwise.
     */
    return_code_t handle_events(paint_t *paint);

#endif
