/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** my_atoi
*/

#include <detail.h>
#include <unistd.h>

int my_rows(char *tab, detail_t *dt)
{
    int pows = 1;
    int rows = 0;
    int j = 0;

    for (int i = 0; tab[i] >= '0' && tab[i] <= '9'; i++)
        pows = pows * 10;
    pows = pows / 10;
    for (j = 0; tab[j] >= '0' && tab[j] <= '9'; j++) {
        rows = rows + (tab[j] - 48) * pows;
        pows = pows / 10;
    }
    return (rows);
}