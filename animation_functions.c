/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** animation_functions
*/

#include "include/my.h"

void move_rect(sfIntRect *rect, int offset, int max_value, sfClock *clock)
{
    rect->left = (rect->left + offset) % max_value;
    sfClock_restart(clock);
}

int nyan_pos(nyan_t *nyan, sfRenderWindow *window)
{
    if ((nyan->pos.x > sfRenderWindow_getSize(window).x ||
        nyan->pos.y > sfRenderWindow_getSize(window).y ||
        (nyan->pos.y < 0 && nyan->pos.x >
        sfRenderWindow_getSize(window).x / 2)) && nyan->is_shot == 0) {
        nyan->is_shot = 1;
        nyan->is_outbound = 1;
        return (-100000);
    }
    return (0);
}

int game_render(m_sprites_t *list, sfIntRect rect, sfVector2f *last_clic,
                sfText **text)
{
    sfRenderWindow_drawSprite(list->window, list->s_list[1], NULL);
    int res = update_nyan(list->n_list, list->window, rect, last_clic);
    sfRenderWindow_drawSprite(list->window, list->s_list[2], NULL);
    sfRenderWindow_drawSprite(list->window, list->s_list[3], NULL);
    sfRenderWindow_drawSprite(list->window, list->s_list[4], NULL);
    sfRenderWindow_drawSprite(list->window, list->s_list[5], NULL);
    sfRenderWindow_drawText(list->window, text[0], NULL);
    sfRenderWindow_drawText(list->window, text[1], NULL);
    sfRenderWindow_drawText(list->window, text[2], NULL);
    move_ptr(list->window, list->s_list[0]);
    return (res);
}
