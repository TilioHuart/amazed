/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** Bfs header
*/

#ifndef BFS_H_
    #define BFS_H_
    #include "../map.h"

typedef struct encountered_room_s {
    map_t *map;
    struct encountered_room_s *next;
} encountered_room_t;

typedef struct room_queue_s {
    map_t *map;
    struct room_queue_s *next;
} room_queue_t;

typedef struct shortest_path_s {
    map_t *room;
    struct shortest_path_s *next;
} shortest_path_t;

int get_shortest_path(map_t *map, const char *end_room,
    shortest_path_t **shortest_path);

#endif
