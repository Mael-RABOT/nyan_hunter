/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** cursor
*/

#include "include/my.h"

sfSprite *make_ptr(void)
{
    sfTexture *texture = sfTexture_createFromFile("ress/target2.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, 0);
    return (sprite);

}

void move_ptr(sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2f position;
    position.x = (float) sfMouse_getPositionRenderWindow(window).x - 20;
    position.y = (float) sfMouse_getPositionRenderWindow(window).y - 20;
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
