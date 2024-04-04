/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** link_handling.c
*/

#include "my_macros.h"
#include "map.h"
#include "my.h"
#include <stdio.h>

static int retrieve_len_link(char **link, size_t *len)
{
    if (link == NULL)
        return FAILURE;
    for (size_t i = 0; link[i] != NULL; i += 1)
        *len += 1;
    return SUCCESS;
}

static int find_link(char *instruction)
{
    char **link = 0;
    size_t len = 0;

    if (instruction == NULL)
        return FAILURE;
    link = my_str_to_word_array(instruction, " ");
    if (retrieve_len_link(link, &len) == FAILURE)
        return FAILURE;
    if (len == 1 && my_strncmp(instruction, "#", 1) != 0)
        return 1;
    return SUCCESS;
}

int handle_link(map_t *map, char **instruction)
{
    size_t beginning = 0;

    if (map == NULL || instruction == NULL)
        return FAILURE;
    for (size_t i = 1; instruction[i] != NULL; i += 1)
        if (find_link(instruction[i]) == 1) {
            beginning = i;
            break;
        }
    if (beginning == 0)
        return FAILURE;
    write(1, "#tunnels\n", my_strlen("#tunnels\n"));
    for (size_t i = beginning; instruction[i] != NULL; i += 1) {
        write(1, instruction[i], my_strlen(instruction[i]));
        write(1, "\n", 1);
    }
    return SUCCESS;
}
