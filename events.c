/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** events
*/

#include "include/my.h"

void manage_click(sfMouseButtonEvent event, sfVector2f *last_clic,
    int *bullet, sfRenderWindow *window)
{
    last_clic->x = event.x;
    last_clic->y = event.y;
}

void menu_clic(sfMouseButtonEvent event, sfVector2f *last_clic)
{
    last_clic->x = event.x;
    last_clic->y = event.y;
}

void analyse_event(sfRenderWindow *window, sfEvent event,
    sfVector2f *last_clic, int *bullet)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : "";
        (event.type == sfEvtMouseButtonPressed) ?
        manage_click(event.mouseButton, last_clic, bullet, window) : "";
    }
}

void check_close(sfRenderWindow *window, sfEvent event, sfVector2f *last_clic)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : "";
        (event.type == sfEvtMouseButtonPressed) ?
            menu_clic(event.mouseButton, last_clic) : "";
    }
}
