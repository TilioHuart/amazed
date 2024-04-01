/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** Retrieve the user inputs to build the maze
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_macros.h"
#include "my_types.h"
#include "my.h"

static char *assign_str(char *str, char *buf, size_t *k)
{
    if (str == NULL) {
        return NULL;
    }
    for (size_t i = 0; buf[i] != '\0'; i += 1) {
        str[*k] = buf[i];
        *k += 1;
    }
    return str;
}

static int retrieve_map()
{
    char *buf = NULL;
    char *str = NULL;
    size_t size_initial = 0;
    size_t size = 0;
    size_t k = 0;

    while (getline(&buf, &size, stdin) > 0) {
        str = my_realloc(str, size_initial, size);
        size_initial += size;
        str = assign_str(str, buf, &k);
    }
    str[k] = '\0';
    printf("%s\n", str);
    return SUCCESS;
}

char **retrieve_info(void)
{
    char **matrix = NULL;

    if (retrieve_map() == FAILURE)
        return NULL;
    return matrix;
}
