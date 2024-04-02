/*
** EPITECH PROJECT, 2024
** amazd
** File description:
** handle_errors.c
*/

#include "my_macros.h"
#include "map.h"
#include "my.h"
#include <stdio.h>

static int check_nb_robots(char **instruction)
{
    char *str = "#number_of_robots\n";

    if (instruction[0] == NULL)
        return FAILURE;
    if (my_str_isnum(instruction[0]) == 0) {
        return FAILURE;
    }
    write(1, str, my_strlen(str));
    write(1, instruction[0], my_strlen(instruction[0]));
    write(1, "\n", 1);
    return SUCCESS;
}

int handle_errors(map_t *map, char **instruction)
{
    if (instruction == NULL)
        return EPITECH_FAILURE;
    if (check_nb_robots(instruction) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
