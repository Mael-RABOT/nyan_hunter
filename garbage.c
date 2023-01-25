/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** garbage
*/

#include "include/my.h"

void garbage(m_sprites_t *list)
{
    for (int i = 0; i < NYAN_NUMBER; i++)
        sfSprite_destroy(list->n_list[i]->sprite);
    for (int j = 0; j < 5; j++)
        sfSprite_destroy(list->s_list[j]);
}

void menu_garbage(sfSprite **list)
{
    for (int i = 0; i < 4; i++)
        sfSprite_destroy(list[i]);
}
