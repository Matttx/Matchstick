/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** No description
*/

#include <unistd.h>
#include <stdlib.h>
#include "detail.h"
#include "my.h"

int main(int ac, char **av)
{
    detail_t *dt = malloc(sizeof(detail_t));
    int result = 0;

    if (ac != 3)
        return (84);
    result = print_game_board(av, dt);
    if (result == 0)
        return (0);
    if (result == 2) {
        write(1, "You lost, too bad...", 21);
        write(1, "\n", 1);
        return (2);
    }else if (result == 1) {
        write(1, "I lost... snif... but I'll get you next time!!", 46);
        write(1, "\n", 1);
        return (1);
    }
    else
        return (84);
}
