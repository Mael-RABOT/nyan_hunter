/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** nyan_functions
*/

#include "include/my.h"

void create_vect(nyan_t *nyan, sfRenderWindow *window);

int update_nyan(nyan_t **list, sfRenderWindow *window,
    sfIntRect rect, sfVector2f *last_clic)
{
    int sum = 0;
    for (int i = 0; i < list[0]->nyan_nb; i++) {
        if (list[i]->is_shot == 0 && list[i]->is_outbound == 0) {
            list[i]->pos = sfSprite_getPosition(list[i]->sprite);
            list[i]->is_shot = check_shot(list[i], last_clic);
            sfSprite_setTextureRect(list[i]->sprite, rect);
            sfSprite_move(list[i]->sprite, list[i]->vect);
            sfRenderWindow_drawSprite(window, list[i]->sprite, NULL);
            sum += nyan_pos(list[i], window);
        }
        if (list[i]->is_shot == 1 && list[i]->as_explode < 7) {
            sum++;
            create_vect(list[i], window);
            sfSprite_setPosition(list[i]->sprite, list[i]->pos);
            list[i]->is_shot = 0;
        }
    }
    return (sum);
}

nyan_t *create_nyan(int nyan_nb)
{
    nyan_t *res;
    res = malloc(sizeof(nyan_t));
    res->is_shot = 0;
    res->explo_rect.left = 0;
    res->is_outbound = 0;
    res->explo_rect.top = 0;
    res->explo_rect.width = 230;
    res->explo_rect.height = 230;
    res->as_explode = 0;
    res->texture = sfTexture_createFromFile("ress/nyan.png", NULL);
    res->sprite = sfSprite_create();
    sfSprite_setTexture(res->sprite, res->texture, 0);
    res->nyan_nb = nyan_nb;
    return (res);
}

void create_vect(nyan_t *nyan, sfRenderWindow *window)
{
    nyan->vect.x = randm(3, 5);
    nyan->vect.y = 0;
    nyan->pos.x = -100;
    nyan->pos.y = sfRenderWindow_getSize(window).y / randm(2, 4);
    nyan->start.x = nyan->pos.x;
    nyan->start.y = nyan->pos.y;
}

nyan_t **create_nyan_list(int nyan_number, sfRenderWindow *window)
{
    nyan_t **res;
    res = malloc(sizeof(nyan_t) * nyan_number);
    for (int i = 0; i < nyan_number; i++) {
        res[i] = malloc(100);
        res[i] = create_nyan(nyan_number);
        create_vect(res[i], window);
        sfSprite_setPosition(res[i]->sprite, res[i]->pos);
    }
    return (res);
}
