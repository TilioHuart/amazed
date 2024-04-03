/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed
*/

#include "retrieve_infos.h"
#include "my_macros.h"
#include "parser.h"
#include "map.h"
#include "linked_list.h"
#include "amazed.h"
#include <stdio.h>
#include <stdlib.h>

int amazed(void)
{
    map_t *map = create_map();
    info_t *info = malloc(sizeof(info));
    char **instruction = parse_map(map, info);

    if (instruction == NULL)
        return EPITECH_FAILURE;
    return SUCCESS;
}
