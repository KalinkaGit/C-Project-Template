/*
** EPITECH PROJECT, 2023
** PROJECT NAME
** File description:
** TESTS
*/

/* LOCAL INCLUDES */
#include "constants.h"
#include "handlers.h"

/* CRITERION INCLUDES */
#include <criterion/criterion.h>
#include <criterion/redirect.h>


Test(handle_errors, test_handle_errors)
{
    char *argv[] = {"./my_program", "arg1"};
    int argc = 2;

    cr_assert_eq(handle_errors(argc, argv), RETURN_SUCCESS);
}
