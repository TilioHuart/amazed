/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** Retrieve the user inputs to build the maze
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "my_macros.h"
#include "my_types.h"
#include "my.h"

static
int check_line_info(char *buff)
{
    if (buff == NULL)
        return FAILURE;
    if (buff[my_strlen(buff) - 1] == '\n')
        buff[my_strlen(buff) - 1] = '\0';
    return SUCCESS;
}

char **retrieve_info(char **map)
{
    bool_t has_end = FALSE;
    char *buff = NULL;
    size_t size = 0;

    while (!has_end) {
        if (getline(&buff, &size, stdin) < 0)
            return NULL;
        if (check_line_info(buff) == FAILURE)
            return NULL;
        if (buff != NULL) {
            free(buff);
            buff = NULL;
        }
    }
    return map;
}
