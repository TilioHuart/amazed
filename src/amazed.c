/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed
*/

#include "retrieve_infos.h"
#include "my_macros.h"
#include "parser.h"
#include <stdio.h>

int amazed(void)
{
    char **map = parse_map();

    for (size_t i = 0; map[i] != NULL; i += 1)
        printf("%s\n", map[i]);
    return SUCCESS;
}
