/*
** EPITECH PROJECT, 2022
** realloc
** File description:
** realloc
*/

#include "my.h"

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);

    if (ptr == NULL)
        return (new_ptr);
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    new_ptr = my_memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}
