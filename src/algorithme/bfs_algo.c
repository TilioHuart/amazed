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

static
int add_room_to_queue(room_queue_t *queue, map_t *room)
{
    if (queue == NULL)
        return display_error("Unable to load queue\n");
    while (queue->next != NULL)
        queue = queue->next;
    if (queue->map == NULL) {
        queue->map = room;
        return SUCCESS;
    }
    queue->next = malloc(sizeof(room_queue_t));
    if (queue->next == NULL)
        return display_error("Unable to add another room to queue\n");
    queue->next->map = room;
    queue->next->next = NULL;
    return SUCCESS;
}

static
int check_linked_room(room_queue_t *queue,
    encountered_room_t *visited, char const *end_room)
{
    for (size_t i = 0; queue->map->link[i] != NULL; i += 1) {
        if (check_visited(queue->map->link[i], visited) == TRUE)
            continue;
        if (add_visited_room(visited, queue->map->link[i]) == FAILURE)
            return FAILURE;
        if (my_strcmp(queue->map->link[i]->name, end_room))
            return SUCCESS;
        add_room_to_queue(queue, queue->map->link[i]);
    }
    return FAILURE;
}

static
shortest_path_t *retrieve_bfs_shortest_path(shortest_path_t *shortest_path,
    encountered_room_t *visited, char const *end_room)
{
    shortest_path_t *path_head = NULL;
    shortest_path_t *previous_room = NULL;
    encountered_room_t *visited_head = visited;
    encountered_room_t *room_to_check = visited_head;

    while (visited != NULL) {
        if (visited->map == NULL)
            continue;
        if (my_strcmp(visited->map->name, end_room) == 0) {
            shortest_path = malloc(sizeof(shortest_path_t));
            if (shortest_path == NULL)
                return NULL;
            shortest_path->room = visited->map;
            shortest_path->next = NULL;
            path_head = shortest_path;
            continue;
        }
        if (path_head != NULL) {
            if (shortest_path->room->link == NULL)
                continue;
            for (size_t i = 0; shortest_path->room->link[i] != NULL; i += 1) {
                while (room_to_check != NULL) {
                    if (my_strcmp(shortest_path->room->link[i]->name, room_to_check->map->name) == 0) {
                        previous_room = malloc(sizeof(shortest_path_t));
                        if (previous_room == NULL)
                            return NULL;
                        previous_room->room = room_to_check->map;
                        previous_room->next = path_head;
                        path_head = previous_room;
                        break;
                    }
                    room_to_check = room_to_check->next;
                }
                room_to_check = visited_head;
            }
        }
        visited = visited->next;
    }
    return path_head;
}

static
int execute_bfs(encountered_room_t *visited, room_queue_t *queue,
    char const *end_room, shortest_path_t **shortest_path)
{
    if (queue == NULL || queue->map == NULL || queue->map->name == NULL
        || queue->map->link == NULL || visited == NULL || end_room == NULL)
        return display_error("Unable to access the room info\n");
    while (queue != NULL) {
        if (check_linked_room(queue, visited, end_room) == SUCCESS)
            return SUCCESS;
        queue = queue->next;
    }
    *shortest_path = retrieve_bfs_shortest_path(*shortest_path, visited, end_room);
    return FAILURE;
}

int get_shortest_path(map_t *map, const char *end_room, shortest_path_t **shortest_path)
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
    queue->map = map;
    queue->next = NULL;
    return execute_bfs(visited, queue, end_room, shortest_path);
}
