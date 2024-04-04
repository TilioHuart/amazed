/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed.h
*/

#ifndef AMAZED_H_
    #define AMAZED_H_

typedef struct path_s {
    char *start_room;
    char *end_room;
    char **shortest_path;
    char **current_path;
    int shortest_path_length;
    int current_room_number;
} path_t; 

typedef struct info {
    int robots;
    int rooms;
    int link;
    int nb_rooms;
} info_t;

int amazed(void);

#endif
