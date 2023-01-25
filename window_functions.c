/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** window_functions
*/

#include "include/my.h"

void check_window_size(arguments_t *args)
{
    args->size.height = (args->size.height > 1080) ? 1080 : args->size.height;
    args->size.height = (args->size.height < 600 && args->size.height != 0)
        ? 600 : args->size.height;
    args->size.width = (args->size.width > 1920) ? 1920 : args->size.width;
    args->size.width = (args->size.width < 800&& args->size.height != 0)
        ? 800 : args->size.width;
}

sfRenderWindow *create_window(arguments_t *arguments)
{
    sfRenderWindow *window;
    check_window_size(arguments);
    int width = (arguments->size.width == 0) ? 1920 : arguments->size.width;
    int height = (arguments->size.height == 0) ? 1080 : arguments->size.height;
    sfVideoMode mode = {width, height, 32};
    window = sfRenderWindow_create(mode, "Nyan hunter",
    sfClose | sfResize, NULL);
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
