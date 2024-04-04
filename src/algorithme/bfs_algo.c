/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** Pathfinding algorithme
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "algorithme/bfs.h"
#include "my_alloc.h"
#include "amazed.h"
#include "map.h"
#include "my_macros.h"
#include "my.h"
#include "my_types.h"

static
int check_visited(map_t const *map, encountered_room_t *visited)
{
    if (map == NULL) {
        display_error("Unable to check map\n");
        return FALSE;
    }
    if (visited == NULL) {
        display_error("Unable to check visited\n");
        return FALSE;
    }
    while (visited != NULL) {
        if (my_strcmp(visited->map->name, map->name) == 0)
            return TRUE;
        visited = visited->next;
    }
    return FALSE;
}

static
int add_visited_room(encountered_room_t *visited, map_t *current_room)
{
    if (visited == NULL || current_room == NULL) {
        return display_error("Unable to retrieve the visited room\n");
    }
    if (visited->map == NULL) {
        visited->map = current_room;
        visited->next = NULL;
        return FAILURE;
    }
    while (visited->next != NULL) {
        visited = visited->next;
    }
    visited->next = malloc(sizeof(encountered_room_t));
    if (visited->next == NULL)
        return display_error("Unable to add visited room\n");
    visited->next->map = current_room;
    visited->next->next = NULL;
    return SUCCESS;
}

int execute_bfs(map_t *map, char const *end_room)
{
    encountered_room_t *visited = NULL;
    room_queue_t *queue = NULL;

    if (end_room == NULL || map == NULL)
        return display_error("Struct null for algorithme\n");
    visited = malloc(sizeof(encountered_room_t));
    if (visited == NULL)
        return display_error("Unable to allocate visited memory\n");
    visited->map = map;
    visited->next = NULL;
    queue = malloc(sizeof(room_queue_t));
    if (queue == NULL) {
        free(visited);
        return display_error("Unable to allocate queue memory\n");
    }
    if (map->name == NULL || map->link == NULL)
        return display_error("Unable to access the room info\n");
    while (visited != NULL) {
        for (size_t i = 0; map->link[i] != NULL; i += 1) {
            if (check_visited(map->link[i], visited) == TRUE)
                continue;
            if (add_visited_room(visited, map->link[i]) == FAILURE)
                continue;
        }
    }
    return SUCCESS;
}
