/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    /* SYSTEM INCLUDES */
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    /**
     * @brief Concatenate a string and an int.
     *
     * @param str String.
     * @param nb Number.
     * @return char* New string.
     */
    char *cat_str_int(char *str, int nb);

    /**
     * @brief Check if a string is a digit.
     *
     * @param str String to check.
     * @return int Exit status.
     */
    int is_digit(char *str);

    /**
     * @brief Compute the power of a number.
     *
     * @param nb Number.
     * @param p Power.
     * @return int Result.
     */
    int my_compute_power_rec(int nb, int p);

    /**
     * @brief Get the length of a number.
     *
     * @param nb Number.
     * @return int Length.
     */
    int my_get_nbr_len(int nb);

    /**
     * @brief Get the length of a string.
     *
     * @param str String.
     * @return int Length.
     */
    int my_getnbr(char const *str);

    /**
     * @brief Copy memory
     *
     * @param dest Destination
     * @param src Source
     * @param n Number of bytes to copy
     * @return void* Pointer to the destination
     */
    void *my_memcpy(void *dest, const void *src, size_t n);

    /**
     * @brief Realloc function
     *
     * @param ptr Pointer to the memory to reallocate
     * @param size Size of the new memory
     * @return void* Pointer to the new memory
     */
    void *my_realloc(void *ptr, size_t size);

    /**
     * @brief Compare two strings
     *
     * @param s1 First string
     * @param s2 Second string
     * @return int 0 if the strings are identical, 1 otherwise
     */
    int my_strcmp(char const *s1, char const *s2);

    /**
     * @brief Get the length of a string.
     *
     * @param str String to get the length of.
     * @return int Length of the string.
     */
    int my_strlen(char const *str);

    /**
     * @brief Compare two strings to n characters.
     *
     * @param s1 First string to compare.
     * @param s2 Second string to compare.
     * @param n Number of characters to compare.
     * @return int Return the difference between the two strings.
     */
    int my_strncmp(char const *s1, char const *s2, int n);

    /**
     * @brief Find a string in another string.
     *
     * @param str String to search in.
     * @param to_find String to find.
     * @return char* Pointer to the first occurence of the string to find.
     */
    char *my_strstr(char *str, char *to_find);

    /**
     * @brief Concatenate two strings.
     *
     * @param dest Destination string.
     * @param src Source string.
     * @return char* New string.
     */
    char *my_strcat(char *dest, char *src);

    /**
     * @brief Copy a string.
     *
     * @param dest Destination string.
     * @param src Source string.
     * @return char* New string.
     */
    char *my_strcpy(char *dest, char const *src);

    /**
     * @brief Convert a number to a string.
     *
     * @param number Number to convert.
     * @return char* String.
     */
    char *my_itoa(int number);

    /**
     * @brief Get the length of an array.
     *
     * @param array Array to get the length of.
     * @return int Length of the array.
     */
    int my_array_len(char **array);

    /**
     * @brief Duplicate a string.
     *
     * @param str String to duplicate.
     * @return char* New string.
     */
    char *my_strdup(char const *src);

    /**
     * @brief Find a string in another string.
     *
     * @param str String to search in.
     * @param to_find String to find.
     * @return char* Pointer to the first occurence of the string to find.
     */
    char *my_strstr(char *str, char *to_find);

    /**
     * @brief Check if a string is alphanumeric.
     *
     * @param str String to check.
     * @return bool True if the string is alphanumeric, false otherwise.
     */
    bool my_alphanum(char *str);

#endif
