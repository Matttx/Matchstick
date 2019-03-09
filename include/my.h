/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** No description
*/

#ifndef CPE_MATCHSTICK_2018_MY_H
#define CPE_MATCHSTICK_2018_MY_H

#include "detail.h"

int my_rows(char *tab);
int print_game_board(char **av, detail_t *dt);
int error_matches(detail_t *dt, char **buffer, int match_on_line);
int verif_positive_number(char *tab);
int error_line(detail_t *dt, char *tab);
int game(detail_t *dt, char **buffer);
int my_put_nbr(int nb);
int informations(detail_t *dt, char **buffer);
char **remove_matches(detail_t *dt, char **buffer);
void my_putchar(char c);
char **ai_gestion(detail_t *dt, char **buffer);
int count_matches(char **buffer, detail_t *dt);

#endif //CPE_MATCHSTICK_2018_MY_H
