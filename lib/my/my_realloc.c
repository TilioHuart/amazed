/*
** EPITECH PROJECT, 2024
** lib
** File description:
** realoc.c
*/

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *my_memcpy(void *value, void *new_value, size_t size)
{
    char *value_cpy = (char *)value;
    char *new_value_cpy = (char *)new_value;

    if (value == NULL || new_value == NULL)
        return NULL;
    for (size_t i = 0; i < size; i += 1)
        new_value_cpy[i] = value_cpy[i];
    return new_value_cpy;
}

void *my_realloc(void *value, size_t size_init, size_t size_final)
{
    char *new_value = NULL;

    if (value == NULL)
        return malloc(sizeof(char) * size_final);
    if (size_final == 0) {
        free(value);
        return NULL;
    }
    new_value = malloc(sizeof(char) * size_final);
    if (new_value == NULL)
        return NULL;
    if (size_init > size_final)
        new_value = my_memcpy(value, new_value, size_final);
    else
        new_value = my_memcpy(value, new_value, size_init);
    if (new_value == NULL)
        return value;
    free(value);
    return new_value;
}
