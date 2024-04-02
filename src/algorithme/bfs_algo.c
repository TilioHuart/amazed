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
int check_shortest_path(char **shortest_path, char *name, size_t current_path_size)
{
    if (shortest_path == NULL)
        return FAILURE;
    for (size_t i = 0; i <= current_path_size; i += 1) {
        if (shortest_path[i] == NULL)
            break;
        if (my_strcmp(shortest_path[i], shortest_path) == 0)
            return FAILURE;
    }
    return SUCCESS;
}

static
int execute_fbs_algorithme(map_t *map, char *end_room, char **shortest_path,
    int current_room)
{
    if (map == NULL)
        return FAILURE;
    for (size_t i = 0; map->link[i] != NULL; i += 1) {
        if (my_strcmp(map->link[i]->name, end_room) != 0) {
            if (check_shortest_path(shortest_path, map->link[i]->name, i) == FAILURE)
                return FAILURE;
            execute_fbs_algorithme(map->link[i], end_room, shortest_path, current_room + 1);
        }
    }
    return SUCCESS;
}

char **find_path(map_t *map, char *end_room, UNUSED int nb_robots)
{
    char **shortest_path = NULL;
    if (map == NULL)
        return display_error("Map null in algo\n"), NULL;
    shortest_path = malloc(sizeof(char *) * 3);
    if (shortest_path == NULL)
        return display_error("Unable to alloc memory to path\n"), NULL;
    shortest_path[0] = NULL;
    shortest_path[1] = NULL;
    execute_fbs_algorithme(map, end_room, shortest_path, 0);
    return shortest_path;
}
