/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed
*/

#include "retrieve_infos.h"
#include "my_macros.h"
#include <stdio.h>

int amazed(char const *const *argv)
{
    char **matrix = NULL;

    if (argv == NULL)
        return EPITECH_FAILURE;
    matrix = retrieve_info();
    return SUCCESS;
}