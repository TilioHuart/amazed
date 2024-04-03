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

static int handle_room(char **room)
{
    size_t i = 0;

    for (size_t j = 0; room[j] != NULL; j += 1) {
        i += 1;
    }
    if (i < 3)
        return FAILURE;
    return SUCCESS;
}

static int print_rooms(char *instruction, info_t *info)
{
    info->nb_rooms += 1;
    if (info->nb_rooms == 1)
        write(1, "#rooms\n", my_strlen("#rooms\n"));
    write(1, instruction, my_strlen(instruction));
    write(1, "\n", 1);
    return SUCCESS;
}

int adding_rooms(map_t *map, char *instruction, info_t *info)
{
    char **room = NULL;

    if (map == NULL || instruction == NULL)
        return FAILURE;
    if (my_strncmp(instruction, "##", 2) == 0)
        return SUCCESS;
    room = my_str_to_word_array(instruction, " ");
    if (handle_room(room) == FAILURE)
        return FAILURE;
    print_rooms(instruction, info);
    info->rooms = TRUE;
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
