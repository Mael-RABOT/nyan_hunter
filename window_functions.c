/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** window_functions
*/

#include "include/my.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode mode = {width, height, 32};
    window = sfRenderWindow_create(mode, "Nyan hunter",
        sfResize | sfClose, NULL);
    return (window);
}

sfSprite *make_background(void)
{
    sfTexture *bg_texture = sfTexture_createFromFile("ress/bg.png", NULL);
    sfSprite *bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg_sprite, bg_texture, 0);
    return (bg_sprite);
}

sfSprite *make_ship(void)
{
    sfTexture *ship_texture = sfTexture_createFromFile("ress/ship3.png", NULL);
    sfSprite *ship_sprite = sfSprite_create();
    sfSprite_setTexture(ship_sprite, ship_texture, 0);
    return (ship_sprite);
}
