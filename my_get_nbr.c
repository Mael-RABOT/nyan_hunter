/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** my_get_nbr
*/

#include "include/my.h"

int my_getnbr(const char *buffer)
{
    int i = 0;
    int res = 0;
    int mult = 1;
    int is_neg = (buffer[0] == '-') ? 1 : 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    for (int ite = is_neg; ite < i; ite++) {
        res += (buffer[i - ite - 1 + is_neg] - 48) * mult;
        mult = mult * 10;
    }
    return (is_neg == 1) ? -res : res;
}

unsigned int my_getnbr_parser(const char *buffer)
{
    int i = 0;
    unsigned int res = 0;
    int mult = 1;
    if (buffer[0] == '-')
        return (0);
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    for (int ite = 0; ite < i; ite++) {
        res += (buffer[i - ite - 1] - 48) * mult;
        mult = mult * 10;
    }
    return (res);
}
