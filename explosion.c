/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** explosion
*/

#include "include/my.h"

int explode(sfRenderWindow *window, nyan_t *nyan)
{
    sfTexture *texture = sfTexture_createFromFile("ress/explo.png", NULL);
    sfSprite *sprite = sfSprite_create();
    nyan->sprite = sprite;
    return (1);
}

void explo_sound(nyan_t *nyan)
{
    if (nyan->as_explode < 1) {
        sfSoundBuffer *buff =
                sfSoundBuffer_createFromFile("ress/explosion.ogg");
        sfSound *sound = sfSound_create();
        sfSound_setBuffer(sound, buff);
        sfSound_play(sound);
    }
}

void explosion_sprites(nyan_t **list, sfRenderWindow *window, int i)
{
    explo_sound(list[i]);
    sfVector2f scale = {0.5, 0.5};
    sfVector2f pos = {list[i]->pos.x + 4, list[i]->pos.y - 37};
    sfTexture *tex = sfTexture_createFromFile("ress/explo.png", NULL);
    list[i]->explo_rect.left += 230;
    sfSprite_setTexture(list[i]->sprite, tex, 0);
    sfSprite_setScale(list[i]->sprite, scale);
    sfSprite_setTextureRect(list[i]->sprite, list[i]->explo_rect);
    sfSprite_setPosition(list[i]->sprite, pos);
    sfRenderWindow_drawSprite(window, list[i]->sprite, NULL);
    list[i]->as_explode += 1;
}
