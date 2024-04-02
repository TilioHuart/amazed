/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** Pathfinding algorithme
*/

#include <stdio.h>
#include "map.h"
#include "my_macros.h"
#include "my.h"
#include "my_types.h"

static
int execute_fbs_algorithme(map_t *map, char *end_room)
{
    if (map == NULL)
        return FAILURE;
    for (size_t i = 0; map->link[i] != NULL; i += 1) {
        if (my_strcmp(map->link, end_room) != 0)
            execute_fbs_algorithme(map->link[i], end_room);
    }
}

int find_path(map_t *map, char *end_room, UNUSED int nb_robots)
{
    if (map == NULL)
        return display_error("Map null in algo\n"), FAILURE;
    execute_fbs_algorithme(map, end_room);
    return SUCCESS;
}
