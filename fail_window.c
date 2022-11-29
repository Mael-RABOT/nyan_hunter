/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** fail_window
*/

#include "include/my.h"

void close_event(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event))
        (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : "";
}

sfSprite *make_loose_title(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("ress/loose2.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, 0);
    sfVector2f vect = {sfRenderWindow_getSize(window).x / 2 - 1250 / 2,
        sfRenderWindow_getSize(window).y / 5};
    sfSprite_setPosition(sprite, vect);
    return (sprite);
}

sfSprite **make_fail_sprites(sfRenderWindow *window)
{
    sfSprite **res;
    res = malloc(8 * 10);
    sfTexture *bck = sfTexture_createFromFile("ress/bg_sheet.png", NULL);
    sfSprite *back = sfSprite_create();
    sfSprite_setTexture(back, bck, 0);
    res[0] = back;
    res[1] = make_ship();
    res[2] = make_loose_title(window);
    return (res);
}

void draw_loose(sfRenderWindow *window, sfSprite **list)
{
    sfRenderWindow_drawSprite(window, list[0], NULL);
    sfRenderWindow_drawSprite(window, list[1], NULL);
    sfRenderWindow_drawSprite(window, list[2], NULL);
}

void fail_window(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    sfVector2f mvment = {-1, 0};
    sfSprite **list = make_fail_sprites(window);
    sfSprite *cursor = make_ptr();
    sfTexture *he = sfTexture_createFromFile("ress/he_man.png", NULL);
    sfSprite *he_man = sfSprite_create();
    sfSprite_setTexture(he_man, he, 0);
    sfVector2f pos = he_man_vect(window);
    while (sfRenderWindow_isOpen(window)) {
        close_event(window);
        sfSprite_setPosition(he_man, pos);
        (sfSprite_getPosition(list[0]).x < -1920 * 6) ?
        sfSprite_setPosition(list[0], mvment) : "";
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_move(list[0], mvment);
        draw_loose(window, list);
        sfRenderWindow_drawSprite(window, he_man, NULL);
        move_ptr(window, cursor);
        sfRenderWindow_display(window);
        }
}
