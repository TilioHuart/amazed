/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** parser.c
*/

#include "my_macros.h"
#include "map.h"
#include "retrieve_infos.h"
#include "handle_errors.h"
#include <stdio.h>

char **parse_map(map_t *map)
{
    char **instruction = retrieve_info();

    if (handle_errors(map, instruction) == FAILURE)
        return NULL;
    return instruction;
}
