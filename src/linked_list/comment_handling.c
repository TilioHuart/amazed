/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** comment_handling.c
*/

#include "amazed.h"
#include "my_macros.h"
#include "my.h"

static int handle_start_end(info_t *info, char *instruction, size_t *error)
{
    info->nb_rooms += 1;
    if (info->nb_rooms == 1)
        write(1, "#rooms\n", my_strlen("#rooms\n"));
    if (my_strcmp(instruction, "##start") == 0 && info->start == FALSE)
        info->start = TRUE;
    if (my_strcmp(instruction, "##end") == 0 && info->end == FALSE)
        info->end = TRUE;
    if ((info->start > TRUE && my_strcmp(instruction, "##start") == 0)
        || (info->end > TRUE &&
        my_strcmp(instruction, "##end") == 0)) {
        *error = 1;
        return FAILURE;
    }
    return SUCCESS;
}

int handle_comment(char *instruction, info_t *info, size_t *error)
{
    if (my_strncmp(instruction, "#", 1) == 0 &&
        my_strcmp(instruction, "##start") != 0 &&
        my_strcmp(instruction, "##end") != 0)
        return 1;
    if (my_strcmp(instruction, "##start") == 0 ||
        my_strcmp(instruction, "##end") == 0) {
            if (handle_start_end(info, instruction, error) == FAILURE)
                return FAILURE;
            write(1, instruction, my_strlen(instruction));
            write(1, "\n", 1);
            return 1;
        }
    return SUCCESS;
}
