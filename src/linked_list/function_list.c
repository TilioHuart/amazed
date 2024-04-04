/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** function_list.c
*/

#include "map.h"
#include "my_macros.h"
#include "my.h"
#include "amazed.h"
#include <stdlib.h>

static int check_link(char **room, size_t *i, size_t *j, int **link)
{
    if (room[*i][*j] == '-') {
        **link = TRUE;
    }
    return SUCCESS;
}

static int find_link(char **room, int *link)
{
    for (size_t i = 0; room[i] != NULL; i += 1)
        for (size_t j = 0; room[i][j] != '\0'; j += 1)
            check_link(room, &i, &j, &link);
    return SUCCESS;
}

static int handle_room(char **room, info_t *info)
{
    size_t i = 0;
    int link = FALSE;

    for (size_t j = 0; room[j] != NULL; j += 1) {
        i += 1;
    }
    if (i == 1) {
        find_link(room, &link);
        if (link == TRUE) {
            info->rooms = TRUE;
            return SUCCESS;
        }
    }
    if (i < 3)
        return FAILURE;
    return SUCCESS;
}

static int print_rooms(char *instruction, info_t *info)
{
    if (info->rooms != TRUE) {
        info->nb_rooms += 1;
        if (info->nb_rooms == 1)
            write(1, "#rooms\n", my_strlen("#rooms\n"));
        write(1, instruction, my_strlen(instruction));
        write(1, "\n", 1);
    }
    return SUCCESS;
}

static int handle_comment(char *instruction, info_t *info)
{
    if (my_strncmp(instruction, "##", 2) == 0 &&
        my_strcmp(instruction, "##start") != 0 &&
        my_strcmp(instruction, "##end") != 0)
        return 1;
    if (my_strcmp(instruction, "##start") == 0 ||
        my_strcmp(instruction, "##end") == 0) {
            info->nb_rooms += 1;
            if (info->nb_rooms == 1)
                write(1, "#rooms\n", my_strlen("#rooms\n"));
            write(1, instruction, my_strlen(instruction));
            write(1, "\n", 1);
            return 1;
        }
    return SUCCESS;
}

static int retrieve_room(char **room, map_t *map)
{
    map_t *tmp = malloc(sizeof(map_t));

    if (room == NULL || *room == NULL || map == NULL)
        return FAILURE;
    while (map->next != NULL)
        map = map->next;
    map->next = tmp;
    tmp->name = my_strdup(room[0]);
    tmp->next = NULL;
    return SUCCESS;
}

int adding_rooms(map_t *map, char *instruction, info_t *info)
{
    char **room = NULL;

    if (map == NULL || instruction == NULL)
        return FAILURE;
    if (handle_comment(instruction, info) == 1)
        return SUCCESS;
    room = my_str_to_word_array(instruction, " ");
    if (handle_room(room, info) == FAILURE)
        return FAILURE;
    print_rooms(instruction, info);
    if (info->rooms != TRUE)
        retrieve_room(room, map);
    return SUCCESS;
}

map_t *create_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->name = NULL;
    map->link = NULL;
    map->next = NULL;
    return map;
}
