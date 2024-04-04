/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed.h
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include <stddef.h>

<<<<<<< HEAD
typedef struct path_s {
    char *start_room;
    char *end_room;
    char **shortest_path;
    char **current_path;
    size_t shortest_path_length;
    size_t current_room_number;
} path_t;

=======
>>>>>>> 718f5b90eae09003368050a853da7e1a60ff56b4
typedef struct info {
    char **rooms_name;
    char *start_name;
    char *end_name;
    int start;
    int end;
    size_t i;
    size_t size_initial;
    size_t size_final;
    int robots;
    int rooms;
    int link;
    int nb_rooms;
} info_t;

int amazed(void);

#endif
