/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** fail_window
*/

#include "include/my.h"

sfSprite *make_victory_title(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("ress/victory2.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.75, 0.75};
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, 0);
    sfVector2f vect = {sfRenderWindow_getSize(window).x / 2 - 1921 * 0.75 / 2,
        sfRenderWindow_getSize(window).y / 5};
    sfSprite_setPosition(sprite, vect);
    return (sprite);
}

sfSprite **make_vict_sprites(sfRenderWindow *window)
{
    sfSprite **res;
    res = malloc(8 * 10);
    sfTexture *bck = sfTexture_createFromFile("ress/bg_sheet.png", NULL);
    sfSprite *back = sfSprite_create();
    sfSprite_setTexture(back, bck, 0);
    res[0] = back;
    res[1] = make_ship();
    res[2] = make_victory_title(window);
    return (res);
}

void draw_victory(sfRenderWindow *window, sfSprite **list)
{
    sfRenderWindow_drawSprite(window, list[0], NULL);
    sfRenderWindow_drawSprite(window, list[1], NULL);
    sfRenderWindow_drawSprite(window, list[2], NULL);
}

void victory_window(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    sfVector2f mvment = {-1, 0};
    sfSprite **list = make_vict_sprites(window);
    sfSprite *cursor = make_ptr();
    while (sfRenderWindow_isOpen(window)) {
        close_event(window);
        (sfSprite_getPosition(list[0]).x < -1920 * 6) ?
        sfSprite_setPosition(list[0], mvment) : "";
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_move(list[0], mvment);
        draw_victory(window, list);
        move_ptr(window, cursor);
        sfRenderWindow_display(window);
    }
}
