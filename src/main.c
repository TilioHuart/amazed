/*
** EPITECH PROJECT, 2024
** Amazed
** File description:
** Main
*/

#include "my_macros.h"
#include "my.h"
#include "amazed.h"

int main(int const argc, UNUSED char const *const *argv)
{
    if (argc != 1)
        return display_error("Wrong number of arguments\n");
    return amazed();
}
