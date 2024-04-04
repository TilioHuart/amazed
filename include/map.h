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
    char *x;
    char *y;
    struct map **link;
    struct map *next;
} map_t;

#endif
