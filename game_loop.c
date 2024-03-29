/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** game_loop
*/

#include "include/my.h"

score_t *create_score_t(int live_args)
{
    score_t *res;
    res = malloc(8 * 3);
    res->score = 0;
    res->last_score = 0;
    res->health = (live_args == 0) ? HEALT_NUMBER : live_args;
    return (res);
}

void render_text(sfText **text_list, int bullets, score_t *score)
{
    sfText_setString(text_list[0], int_to_nbr(bullets));
    sfText_setString(text_list[1], int_to_nbr(score->score * 1000));
    sfText_setString(text_list[2], int_to_nbr(score->health));
}

void damage(score_t **score, sfRenderWindow *window, sfText *text)
{
    (*score)->score = (*score)->last_score;
    if ((*score) - 1 > 0) {
        (*score)->score -= 1;
        sfText_setString(text, int_to_nbr((*score)->score * 1000));
        sfRenderWindow_drawText(window, text, NULL);
    }
    (*score)->health -= 1;
    ((*score)->health <= 0) ? fail_window(window) : "";
}

void check_score(sfRenderWindow *window, score_t *score, sfText **text_list,
    int score_value)
{
    int score_target = (score_value == 0) ? SCORE_TO_WIN : score_value;
    (score->score < 0) ? damage(&score, window, text_list[1]) : "";
    (score->score >= score_target) ? victory_window(window) : "";
}

void game_loop(sfRenderWindow *window, sfEvent event, int num,
    arguments_t *args)
{
    m_sprites_t *list = create_sprites(window, num);
    int bullets = BULLET_NUMBER;
    score_t *score = create_score_t(args->live);
    sfClock *clock = sfClock_create();
    sfText **text_list = create_texts(window, score->health);
    sfVector2f last_clic = {(float) sfRenderWindow_getSize(window).x,
                            (float) sfRenderWindow_getSize(window).y};
    sfIntRect rect = {0, 0, 124, 42};
    while (sfRenderWindow_isOpen(window)) {
        analyse_event(window, event, &last_clic, &bullets);
        sfRenderWindow_clear(window, sfBlack);
        (sfClock_getElapsedTime(clock).microseconds / 1000000.0 > 0.1) ?
        move_rect(&rect, 124, 372, clock) : "";
        render_text(text_list, bullets, score);
        score->last_score = score->score;
        score->score += game_render(list, rect, &last_clic, text_list);
        check_score(window, score, text_list, args->score_to_win);
        sfRenderWindow_display(window);
    }
    garbage(list);
}
