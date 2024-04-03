/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-lucas.ludovic
** File description:
** free.c
*/

#include "map.h"
#include "my_macros.h"
#include "my.h"
#include "amazed.h"
#include <stdlib.h>

void free_map(map_t *map)
{
    if (map == NULL)
        return;
    if (map->name != NULL)
        free(map->name);
    if (map->link != NULL)
        free(map->link);
    free(map);
}