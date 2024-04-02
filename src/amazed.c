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
#include <stdio.h>
#include <stdlib.h>

int amazed(void)
{
    map_t *map = malloc(sizeof(map_t));
    char **instruction = parse_map(map);

    for (size_t i = 0; instruction[i] != NULL; i += 1)
        printf("%s\n", instruction[i]);
    return SUCCESS;
}
