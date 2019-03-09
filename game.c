/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** No description
*/

#include <unistd.h>
#include "detail.h"
#include "my.h"

int game(detail_t *dt, char **buffer)
{
    write(1, "Your turn:", 10);
    write(1, "\n", 1);
    if (informations(dt, buffer) == 1)
        return (-1);
    if (count_matches(buffer, dt) == 1)
        return (1);
    dt->turn += 1;
    write(1, "\n", 1);
    write(1, "AI's turn...", 12);
    write(1, "\n", 1);
    ai_gestion(dt, buffer);
    for (int i = 0; i < dt->nb_line; i++)
        write(1, buffer[i], dt->nb_cols);
    if (count_matches(buffer, dt) == 1)
        return (1);
    dt->turn += 1;
    write(1, "\n", 1);
    return (0);
}