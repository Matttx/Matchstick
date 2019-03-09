/*
** EPITECH PROJECT, 2018
** ai.c
** File description:
** No description
*/

#include <stdlib.h>
#include <unistd.h>
#include "detail.h"
#include "my.h"

int victory_possibility(detail_t *dt, char **buffer,
        int *max_pipe, int *line_more_pipe)
{
    int pipe = 0;
    int j = dt->nb_cols;
    int k = 0;

    for (int i = 0; i < dt->nb_line; i++) {
        for (int k = 0; k < dt->nb_cols; k++)
            if (buffer[i][k] == '|')
                pipe++;
        if (pipe > *max_pipe) {
            *max_pipe = pipe;
            *line_more_pipe = i;
        }
    }
    k = *max_pipe - 1;
    for (; *max_pipe - 1 > 0; (j)--)
        if (buffer[*line_more_pipe][j] == '|') {
            buffer[*line_more_pipe][j] = ' ';
            *max_pipe -= 1;
        }
    return (k);
}

int natural_choice(detail_t *dt, char **buffer, long *l, long *h)
{
    int j = dt->nb_cols;
    long k = 1;
    int matches_on_line = 0;

    *h = k;
    *l = 1;
    while (k > 0) {
        for (int i = 0; buffer[*l][i] != '\0'; i++)
            if (buffer[*l][i] == '|')
                matches_on_line++;
        if (matches_on_line >= k) {
            if (buffer[*l][j] == '|') {
                buffer[*l][j] = ' ';
                k -= 1;
            }
            j--;
        }else
            (*l)++;
    }
}

int ai_loose(detail_t *dt, char **buffer)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < dt->nb_line; i++) {
        for (j = 0; j < dt->nb_cols; j++) {
            if (buffer[i][j] == '|') {
                buffer[i][j] = ' ';
                k = i;
            }
        }
    }
    write(1, "AI removed 1 match(es) from line ", 33);
    my_put_nbr(k);
    write(1, "\n", 1);
}

int write_info(long l, long k)
{
    write(1, "AI removed ", 11);
    my_put_nbr(k);
    write(1, " match(es) from line ", 21);
    my_put_nbr(l);
    write(1, "\n", 1);
}

char **ai_gestion(detail_t *dt, char **buffer)
{
    long k = 0;
    long l = 0;

    if (dt->rest_matches == 1)
        ai_loose(dt, buffer);
    else {
        natural_choice(dt, buffer, &l, &k);
        write_info(l, k);
    }
    return (buffer);
}