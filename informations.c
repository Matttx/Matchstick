/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** No description
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "detail.h"
#include "my.h"

int print_info(detail_t *dt, char **buffer)
{
    write(1, "Player removed ", 15);
    my_put_nbr(dt->matches);
    write(1, " match(es) from line ", 21);
    my_put_nbr(dt->line);
    my_putchar('\n');
    remove_matches(dt, buffer);
    for (int i = 0; i < dt->nb_line; i++)
        write(1, buffer[i], dt->nb_cols);
}

int verif_positive_number(char *tab)
{
    for (int i = 0; tab[i] != '\n'; i++) {
        if (tab[i] < '0' || tab[i] > '9') {
            write(1, "Error: invalid input (positive number expected)", 47);
            write(1, "\n", 1);
            return (1);
        }
    }
    return (0);
}

int informations(detail_t *dt, char **buffer)
{
    size_t size = 0;
    char *tab = NULL;
    int match_on_line = 0;

    write(1, "Line: ", 6);
    if (getline(&tab, &size, stdin) == -1)
        return (1);
    if (verif_positive_number(tab) == 1)
        return (informations(dt, buffer));
    if (error_line(dt, tab) == 1)
        return (informations(dt, buffer));
    write(1, "Matches: ", 9);
    if (getline(&tab, &size, stdin) == -1)
        return (1);
    if (verif_positive_number(tab) == 1)
        return (informations(dt, buffer));
    dt->matches = my_rows(tab);
    if (error_matches(dt, buffer, match_on_line) == 1)
        return (informations(dt, buffer));
    print_info(dt, buffer);
}