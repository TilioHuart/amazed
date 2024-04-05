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
    map_t *current = map;
    map_t *next;

    if (map == NULL)
        return;
    while (current != NULL) {
        next = current->next;
        for (int i = 0; map->name[i] != NULL; i += 1)
            free(map->name[i]);
        free(map->name);
        free(map);
        free(current);
        current = next;
    }
}
