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

    /**
     * @brief Handle arguments of the program.
     *
     * @param argc Arguments count.
     * @param argv Arguments vector.
     * @return int 0 if handling was successful, -1 otherwise.
     */
    return_code_t handle_args(int argc, char *argv[]);

    /**
     * @brief Handle errors of the program.
     *
     * @param argc Arguments count.
     * @param argv Arguments vector.
     * @return int 0 if handling was successful, -1 otherwise.
     */
    return_code_t handle_errors(int argc, char *argv[]);

#endif
