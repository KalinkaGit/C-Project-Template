/*
** EPITECH PROJECT, 2023
** PROJECT NAME
** File description:
** Header file for constants used throughout the project.
*/

#ifndef CONSTANTS_H_
    #define CONSTANTS_H_

    /**
     * @brief Program exit codes.
     */
    typedef enum
    {
        EXIT_SUCCESS = 0,    /**< Program ran successfully. */
        EXIT_FAILURE = 84    /**< Program failed. */
    } exit_code_t;

    /**
     * @brief Function return codes.
     */
    typedef enum
    {
        RETURN_SUCCESS = 0,   /**< Function ran successfully. */
        RETURN_FAILURE = -1,  /**< Function failed. */
        RETURN_NOW = 1        /**< Function ran successfully but program 
                                   should not continue. */
    } return_code_t;

#endif /* !CONSTANTS_H_ */
