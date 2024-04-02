/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** Pathfinding algorithme
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "amazed.h"
#include "map.h"
#include "my_macros.h"
#include "my.h"
#include "my_types.h"

static
int check_shortest_path(path_t *path, map_t *map)
{
    if (path == NULL || map == NULL)
        return FAILURE;
    return SUCCESS;
}

static
int execute_fbs_algorithme(map_t *map, path_t *path)
{
    if (map == NULL)
        return FAILURE;
    for (size_t i = 0; map->link[i] != NULL; i += 1) {
        if (my_strcmp(map->link[i]->name, path->end_room) != 0) {
            if (check_shortest_path(path, map->link[i]) == FAILURE)
                return FAILURE;
            execute_fbs_algorithme(map->link[i], path);
        }
    }
    return SUCCESS;
}

char **find_path(map_t *map, path_t *path)
{
    char **shortest_path = NULL;
    if (map == NULL || path == NULL)
        return display_error("Structs null in algo\n"), NULL;
    shortest_path = malloc(sizeof(char *) * 3);
    if (shortest_path == NULL)
        return display_error("Unable to alloc memory to path\n"), NULL;
    shortest_path[0] = NULL;
    shortest_path[1] = NULL;
    execute_fbs_algorithme(map, path, shortest_path, 0);
    return shortest_path;
}
