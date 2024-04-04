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
#include "amazed.h"
#include "my.h"
#include "linked_list.h"
#include <stdio.h>

char **parse_map(map_t *map, info_t *info)
{
    char **instruction = retrieve_info();

    info->link = FALSE;
    info->rooms = FALSE;
    info->robots = FALSE;
    info->nb_rooms = 0;
    if (handle_errors(map, instruction, info) == FAILURE)
        return NULL;
    return instruction;
}
