/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** main_text
*/

#include "include/my.h"

sfText *create_health(sfRenderWindow *window, int health)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("ress/pixelart2.ttf");
    sfText_setFont(text, font);
    sfText_setFillColor(text, sfGreen);
    sfVector2f vect = {sfRenderWindow_getSize(window).x / 8 + 120,
    sfRenderWindow_getSize(window).y - 112};
    sfText_setPosition(text, vect);
    sfText_setString(text, int_to_nbr(3));
    return (text);
}

sfText *create_count(sfRenderWindow *window)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("ress/pixelart2.ttf");
    sfText_setFont(text, font);
    sfText_setFillColor(text, sfGreen);
    sfVector2f vect = {sfRenderWindow_getSize(window).x / 8 + 300,
    sfRenderWindow_getSize(window).y - 112};
    sfText_setPosition(text, vect);
    sfText_setString(text, "0");
    return (text);
}

sfText *create_score(sfRenderWindow *window)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("ress/pixelart2.ttf");
    sfText_setFont(text, font);
    sfText_setFillColor(text, sfGreen);
    sfVector2f vect = {sfRenderWindow_getSize(window).x / 8 + 450,
    sfRenderWindow_getSize(window).y - 112};
    sfText_setPosition(text, vect);
    sfText_setString(text, "0");
    return (text);
}

sfText **create_texts(sfRenderWindow *window, int health)
{
    sfText **res;
    res = malloc(8 * 3);
    res[0] = create_count(window);
    res[1] = create_score(window);
    res[2] = create_health(window, health);
    return (res);
}
