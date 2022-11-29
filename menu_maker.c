/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** menu_maker
*/

#include "include/my.h"


sfVector2f he_man_vect(sfRenderWindow *window)
{
    sfVector2f res = {sfRenderWindow_getSize(window).x - 799,
        sfRenderWindow_getSize(window).y - 569};
    return (res);
}

sfSprite *mk_go_but(sfRenderWindow *window, sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromFile("ress/go_but.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, rect);
    sfVector2f vect = {(sfRenderWindow_getSize(window).x / 4) + 120,
        sfRenderWindow_getSize(window).y - 150};
    sfSprite_setPosition(sprite, vect);
    return (sprite);
}

sfSprite *mk_st_but(sfRenderWindow *window, sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromFile("ress/stop_but.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, rect);
    sfVector2f vect = {((sfRenderWindow_getSize(window).x / 4) * 3) - 270,
        sfRenderWindow_getSize(window).y - 150};
    sfSprite_setPosition(sprite, vect);
    return (sprite);
}

sfSprite *make_title(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("ress/title.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, 0);
    sfVector2f vect = {sfRenderWindow_getSize(window).x / 2 - 743 / 2,
        sfRenderWindow_getSize(window).y / 5};
    sfSprite_setPosition(sprite, vect);
    return (sprite);
}

sfSprite **create_sprite_list(sfRenderWindow *window)
{
    sfSprite **res;
    res = malloc(4 * 8);
    sfIntRect rect_go = {0, 0, 140, 100};
    sfIntRect rect_st = {0, 0, 140, 100};
    res[0] = make_ship();
    res[1] = make_title(window);
    res[2] = mk_go_but(window, rect_go);
    res[3] = mk_st_but(window, rect_st);
    res[4] = make_ptr();
    return (res);
}
