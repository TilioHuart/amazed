/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** coordinate_handling.c
*/

#include "my_macros.h"
#include "my.h"
#include <stdio.h>

int handle_coordinate(char **room)
{
    if (room == NULL)
        return FAILURE;
    for (size_t i = 1; room[i] != NULL; i += 1) {
        if (my_str_isnum(room[i]) == 0)
            return FAILURE;
    }
    return SUCCESS;
}
