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

static int initialise_info(info_t *info)
{
    if (info == NULL)
        return FAILURE;
    info->link = FALSE;
    info->rooms = FALSE;
    info->robots = FALSE;
    info->rooms_name = NULL;
    info->i = 0;
    info->size_initial = 0;
    info->size_final = 16;
    info->nb_rooms = 0;
    info->start = FALSE;
    info->end = FALSE;
    return SUCCESS;
}

char **parse_map(map_t *map, info_t *info)
{
    char **instruction = retrieve_info();

    if (initialise_info(info) == FAILURE)
        return NULL;
    if (handle_errors(map, instruction, info) == FAILURE)
        return NULL;
    return instruction;
}
