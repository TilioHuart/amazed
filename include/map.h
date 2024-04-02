/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** map.h
*/

#ifndef MAP_H_
    #define MAP_H_

typedef struct map {
    char *name;
    struct map **link;
    struct map *next;
}

#endif
