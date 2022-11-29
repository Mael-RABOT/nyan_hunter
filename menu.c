/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** menu.c
*/

#include "include/my.h"

void draw_sprites(sfRenderWindow *window, sfSprite **list, int num)
{
    for (int i = 0; i < num; i++)
        sfRenderWindow_drawSprite(window, list[i], NULL);
}

int check_clic(sfRenderWindow *window, sfSprite *sprite, sfVector2f *last_clic)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    if ((pos.x + 140 >= last_clic->x && pos.x <= last_clic->x) &&
        (pos.y + 100 >= last_clic->y && pos.y <= last_clic->y)) {
        last_clic->x = 0;
        last_clic->y = 0;
        return (1);
    }
    return (0);
}

int upt_btn(sfRenderWindow *window, sfSprite **list,
    sfVector2f *last_clic)
{
    sfIntRect rect = {140, 0, 140, 100};
    for (int i = 2; i < 4; i++) {
        if (check_clic(window, list[i], last_clic) == 1) {
            sfSprite_setTextureRect(list[i], rect);
            sfRenderWindow_drawSprite(window, list[i], NULL);
            return (i == 2) ? LAUNCH_GAME : EXIT_WINDOW;
        }
        sfRenderWindow_drawSprite(window, list[i], NULL);
    }
    return (0);
}

int window_selector(sfRenderWindow *window, sfEvent event, int selection)
{
    switch (selection) {
        case 0:
            break;
        case LAUNCH_GAME:
            sfRenderWindow_display(window);
            game_loop(window, event, NYAN_NUMBER);
            break;
        case EXIT_WINDOW:
            sfRenderWindow_display(window);
            sfRenderWindow_close(window);
            break;
    }
    return (EXIT_FAILURE);
}

void menu(sfRenderWindow *window, sfEvent event)
{
    sfSprite **sprite_list = create_sprite_list(window);
    sfClock *clock = sfClock_create();
    sfTexture *bck = sfTexture_createFromFile("ress/bg_sheet3.png", NULL);
    sfSprite *back = sfSprite_create();
    sfVector2f mvment = {-1, 0};
    sfVector2f lst_c;
    sfSprite_setTexture(back, bck, 0);
    while (sfRenderWindow_isOpen(window)) {
        check_close(window, event, &lst_c);
        (sfSprite_getPosition(back).x < -1920 * 6) ?
            sfSprite_setPosition(back, mvment) : "";
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, back, NULL);
        sfSprite_move(back, mvment);
        draw_sprites(window, sprite_list, 4);
        window_selector(window, event, upt_btn(window, sprite_list, &lst_c));
        move_ptr(window, sprite_list[4]);
        sfRenderWindow_display(window);
    }
}
