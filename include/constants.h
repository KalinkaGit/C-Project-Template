/*
** EPITECH PROJECT, 2023
** PROJECT NAME
** File description:
** Header file for constants used throughout the project.
*/

#ifndef CONSTANTS_H_
    #define CONSTANTS_H_

    #define WIDTH 1280
    #define HEIGHT 768

    /**
     * @brief Program exit codes.
     */
    typedef enum {
        CEXIT_SUCCESS = 0,    /**< Program ran successfully. */
        CEXIT_FAILURE = 84    /**< Program failed. */
    } exit_code_t;

    /**
     * @brief Function return codes.
     */
    typedef enum {
        CRETURN_SUCCESS = 0,   /**< Function ran successfully. */
        CRETURN_FAILURE = -1,  /**< Function failed. */
        CRETURN_NOW = 1        /**< Function ran successfully, program stop. */
    } return_code_t;

#endif /* !CONSTANTS_H_ */
