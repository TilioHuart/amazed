/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** Pathfinding algorithme
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_alloc.h"
#include "amazed.h"
#include "map.h"
#include "my_macros.h"
#include "my.h"
#include "my_types.h"

static
void update_current_path(map_t *map, path_t *path)
{
    size_t number_room = 0;

    if (map == NULL || path == NULL)
        return;
    number_room = path->current_room_number;
    path->current_path = my_realloc(path->current_path,
        sizeof(char *) * number_room,
        sizeof(char *) * number_room + 1);
    path->current_path[number_room - 1] = my_strdup(map->name);
    path->current_path[number_room] = NULL;
    path->current_room_number += 1;
}

static
void change_shortest_path(path_t *path)
{
    if (path == NULL)
        return;
    if (path->current_room_number > path->shortest_path_length)
        return;
    if (path->shortest_path == NULL) {
        path->shortest_path = path->current_path;
        return;
    }
    for (size_t i = 0; path->shortest_path[i] != NULL; i += 1) {
        free(path->shortest_path[i]);
    }
    free(path->shortest_path);
    path->shortest_path = path->current_path;
    path->current_path = NULL;
}

static
int check_shortest_path(path_t *path, map_t *map)
{
    size_t index = 0;

    if (path == NULL || map == NULL)
        return FAILURE;
    for (index = 0; path->shortest_path[index] != NULL; index += 1) {
        if (my_strcmp(path->shortest_path[index], map->name) == 0 &&
            path->current_room_number >= index) {
            return FAILURE;
        }
        if (my_strcmp(path->shortest_path[index], map->name) == 0 &&
            path->current_room_number < index)
            change_shortest_path(path);
            break;
    }
    return SUCCESS;
}

static
int execute_fbs_algorithme(map_t *map, path_t *path)
{
    if (map == NULL)
        return FAILURE;
    for (size_t i = 0; map->link[i] != NULL; i += 1) {
        if (my_strcmp(map->link[i]->name, path->end_room) == 0) {
            change_shortest_path(path);
            return SUCCESS;
        }
        if (my_strcmp(map->link[i]->name, path->end_room) != 0) {
            if (check_shortest_path(path, map->link[i]) == FAILURE) {
                return FAILURE;
            }
            execute_fbs_algorithme(map->link[i], path);
            continue;
        }
    }
    return SUCCESS;
}

int find_path(map_t *map, path_t *path)
{
    if (map == NULL || path == NULL)
        return display_error("Structs null in algo\n"), FAILURE;
    if (execute_fbs_algorithme(map, path) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
