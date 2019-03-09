/*
** EPITECH PROJECT, 2018
** error_line_matches.c
** File description:
** No description
*/

#include <unistd.h>
#include "detail.h"
#include "my.h"

int error_line(detail_t *dt, char *tab)
{
    dt->line = my_rows(tab);
    if (dt->line > dt->nb_line - 2 || dt->line <= 0) {
        write(1, "Error: this line is out of range", 32);
        write(1, "\n", 1);
        return (1);
    }
    return (0);
}

int error_matches(detail_t *dt, char **buffer, int matches_on_line)
{
    for (int i = 0; buffer[dt->line][i] != '\0'; i++) {
        if (buffer[dt->line][i] == '|')
            matches_on_line++;
    }
    if (dt->matches > dt->max_matches) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(dt->max_matches);
        write(1, " matches per turn\n", 18);
        return (1);
    } if (dt->matches > matches_on_line) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (1);
    } else if (dt->matches <= 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (1);
    }
    return (0);
}