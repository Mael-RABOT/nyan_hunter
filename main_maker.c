/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** main_maker
*/

#include "include/my.h"

sfSprite *make_bullet_count(sfRenderWindow *window)
{
    sfSprite *res = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("ress/bullets.png", NULL);
    sfSprite_setTexture(res, texture, 0);
    sfVector2f pos = {sfRenderWindow_getSize(window).x / 8 + 120 + 120,
    sfRenderWindow_getSize(window).y - 132};
    sfSprite_setPosition(res, pos);
    return (res);
}

sfSprite *make_score_count(sfRenderWindow *window)
{
    sfSprite *res = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("ress/score.png", NULL);
    sfSprite_setTexture(res, texture, 0);
    sfVector2f pos = {sfRenderWindow_getSize(window).x / 8 + 400,
    sfRenderWindow_getSize(window).y - 135};
    sfSprite_setPosition(res, pos);
    return (res);
}

sfSprite *make_health_count(sfRenderWindow *window)
{
    sfSprite *res = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("ress/health.png", NULL);
    sfSprite_setTexture(res, texture, 0);
    sfVector2f pos = {sfRenderWindow_getSize(window).x / 8 + 60,
    sfRenderWindow_getSize(window).y - 132};
    sfSprite_setPosition(res, pos);
    return (res);
}

sfSprite **game_sprites(sfRenderWindow *window)
{
    sfSprite **res;
    res = malloc(8 * 6);
    res[0] = make_ptr();
    res[1] = make_background();
    res[2] = make_ship();
    res[3] = make_bullet_count(window);
    res[4] = make_score_count(window);
    res[5] = make_health_count(window);
    return (res);
}

m_sprites_t *create_sprites(sfRenderWindow *window, int num)
{
    m_sprites_t *res;
    res = malloc(num * sizeof(nyan_t) + 8 * 6);
    res->window = window;
    res->s_list = game_sprites(window);
    res->n_list = create_nyan_list(num, window);
    return (res);
}
