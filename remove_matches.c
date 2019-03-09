/*
** EPITECH PROJECT, 2018
** remove_matches.c
** File description:
** No description
*/

#include "detail.h"
#include "my.h"

char **remove_matches(detail_t *dt, char **buffer)
{
    int j = dt->nb_cols;
    int i = dt->line;

    while (dt->matches > 0) {
        if (buffer[i][j] == '|') {
            buffer[i][j] = ' ';
            dt->matches -= 1;
        }
        j--;
    }
    return (buffer);
}