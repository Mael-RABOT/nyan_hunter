/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** nyan_is_alive
*/

#include "include/my.h"

int im_still_standing(nyan_t **list, int num)
{
    int sum = 0;
    for (int i = 0; i < num; i++)
        sum += list[i]->is_shot;
    return (sum);
}

int check_shot(nyan_t *nyan, sfVector2f *last_clic)
{
    if (nyan->is_shot == 1)
        return (1);
    if ((nyan->pos.x + 124 > last_clic->x && nyan->pos.x < last_clic->x)
        && (nyan->pos.y + 42 > last_clic->y && nyan->pos.y < last_clic->y)) {
        last_clic->x = 1920 * 2;
        last_clic->y = 1080 * 2;
        return (1);
    }
    return (0);
}

void check_victory(sfRenderWindow *window, int num, nyan_t **list, int bullet)
{
    if (im_still_standing(list, num) >= num) {
        victory_window(window);
    } else if (bullet <= 0) {
        fail_window(window);
    }
}
