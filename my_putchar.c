/*
** EPITECH PROJECT, 2018
** MY_PUTCHAR
** File description:
** PRINT CHAR ASCII
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
