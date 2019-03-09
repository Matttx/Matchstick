/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** No description
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "detail.h"
#include "my.h"

void print_space_pipe(char **buffer, int *j, int *i, detail_t *dt)
{
    for (int f = 0; f < dt->nb_space / 2; f++) {
        buffer[*i][*j] = ' ';
        (*j)++;
    }
    for (int f = 0; f < dt->nb_pipe; f++) {
        buffer[*i][*j] = '|';
        (*j)++;
    }
    for (int f = 0; f < dt->nb_space / 2; f++) {
        buffer[*i][*j] = ' ';
        (*j)++;
    }
}

char **fill_buffer(char **buffer, detail_t *dt)
{
    for (int i = 0; i < dt->nb_line; i++) {
        for (int j = 0; j < dt->nb_cols; j++) {
            if (i == 0 || i == dt->nb_line - 1)
                buffer[i][j] = '*';
            else if (j == 0 || j == dt->nb_cols - 2)
                buffer[i][j] = '*';
            else if (i != 0 && i != dt->nb_line)
                print_space_pipe(buffer, &j, &i, dt);
        }
        if (i != 0 && i != dt->nb_line - 1) {
            dt->nb_pipe += 2;
            dt->nb_space -= 2;
        }
        buffer[i][dt->nb_cols - 2] = '*';
        buffer[i][dt->nb_cols - 1] = '\n';
        buffer[i][dt->nb_cols] = '\0';
    }
    for (int i = 0; i < dt->nb_line; i++)
        write(1, buffer[i], dt->nb_cols);
    return (buffer);
}

int count_matches(char **buffer, detail_t *dt)
{
    int j = 0;
    dt->rest_matches = 0;

    for (int i = 0; i < dt->nb_line ; i++) {
        for (j = 0; buffer[i][j] != '\0'; j++) {
            if (buffer[i][j] == '|')
                dt->rest_matches += 1;
        }
    }
    if (dt->rest_matches == 0)
        return (1);
    return (0);
}

char **malloc_tab(char **buffer, char **av)
{
    for (int i = 0; i < 101; i++) {
        buffer[i] = malloc(sizeof(char) * (my_rows(av[1]) * 2) + 2);
    }
    return (buffer);
}

int print_game_board(char **av, detail_t *dt)
{
    char **buffer = malloc(sizeof(char *) * my_rows(av[1]) + 2);

    dt->nb_line = my_rows(av[1]) + 2;
    if (dt->nb_line - 2 < 2 || dt->nb_line - 2 > 99)
        return (84);
    dt->nb_cols = (my_rows(av[1]) * 2) + 2;
    dt->nb_space = dt->nb_cols - 3;
    dt->nb_pipe = 1;
    dt->max_matches = my_rows(av[2]);
    dt->rest_matches = dt->max_matches;
    buffer = malloc_tab(buffer, av);
    buffer = fill_buffer(buffer, dt);
    write(1, "\n", 1);
    while (dt->rest_matches > 0)
        if (game(dt, buffer) == -1)
            return (0);
    if (dt->turn % 2 == 0)
        return (2);
    else if (dt->turn % 2 == 1)
        return (1);
}