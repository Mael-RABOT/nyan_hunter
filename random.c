/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** random
*/

#include "include/my.h"

int randm_i(int min, int max)
{
    int res;
    while (res < min)
        res = rand() % (max + 1);
    return (res);
}

float randm(int min, int max)
{
    float res;
    while (res < min * 100)
        res = rand() % ((max + 1) * 100);
    res /= 100;
    return (res);
}

char *int_to_nbr(int nb)
{
    int res[32];
    char *tmp;
    int sum = 0;
    while (nb > 0) {
        res[sum] = nb % 10;
        nb = nb / 10;
        sum++;
    }
    tmp = malloc(sum);
    for (int j = sum - 1; j >= 0; j--) {
        tmp[(sum - 1) - j] = res[j] + 48;
    }
    tmp[sum] = '\0';
    return (tmp);
}
