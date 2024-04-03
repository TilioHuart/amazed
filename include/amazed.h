/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed.h
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include <stddef.h>

typedef struct path_s {
    char *start_room;
    char *end_room;
    char **shortest_path;
    char **current_path;
    size_t shortest_path_length;
    size_t current_room_number;
} path_t;

int amazed(void);

#endif
