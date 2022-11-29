/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-BSQ-mael.rabot
** File description:
** my.h
*/

#ifndef TEK1_MY_H_
    #define TEK1_MY_H_

    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
    #define MAX(x, y) (((x) > (y)) ? (x) : (y))

    #define EXIT_WINDOW -42
    #define LAUNCH_GAME 42
    #define HEALT_NUMBER 1
    #define NYAN_NUMBER 4

    #include "mylib.h"
    #include "my_printf.h"
    #include "my_structs.h"

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>

    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/syscall.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdint.h>
    #include <time.h>
    #include <sys/sysmacros.h>
    #include <pwd.h>
    #include <grp.h>
    #include <errno.h>
    #include <string.h>

    int im_still_standing(nyan_t **list, int num);
    int check_shot(nyan_t *nyan, sfVector2f *last_clic);
    int explode(sfRenderWindow *window, nyan_t *nyan);
    int game_render(m_sprites_t *list, sfIntRect rect, sfVector2f *last_clic,
                    sfText **text);
    int update_nyan(nyan_t **list, sfRenderWindow *window,
                    sfIntRect rect, sfVector2f *last_clic);
    int nyan_pos(nyan_t *nyan, sfRenderWindow *window);

    float randm(int min, int max);

    char *int_to_nbr(int nb);
    int randm_i(int min, int max);

    void menu(sfRenderWindow *window, sfEvent event);
    void fail_window(sfRenderWindow *window);
    void victory_window(sfRenderWindow *window);

    nyan_t **create_nyan_list(int nyan_number, sfRenderWindow *window);

    nyan_t *create_nyan(int i);

    void check_victory(sfRenderWindow *window, int num,
        nyan_t **list, int bullet);
    void move_rect(sfIntRect *rect, int offset, int max_value, sfClock *clock);
    void manage_click(sfMouseButtonEvent event, sfVector2f *last_clic,
        int *bullet, sfRenderWindow *window);
    void analyse_event(sfRenderWindow *window,
        sfEvent event, sfVector2f *last_clic, int *bullet);
    void check_close(sfRenderWindow *window, sfEvent event,
        sfVector2f *last_clic);
    void move_ptr(sfRenderWindow *window, sfSprite *sprite);
    void game_loop(sfRenderWindow *window, sfEvent event, int num);
    void check_victory(sfRenderWindow *window, int num, nyan_t **list,
        int bullet);
    void close_event(sfRenderWindow *window);
    void explosion_sprites(nyan_t **list, sfRenderWindow *window, int i);
    void explo_sound(nyan_t *nyan);

    sfText **create_texts(sfRenderWindow *window, int health);


    sfSprite **create_sprite_list(sfRenderWindow *window);

    sfSprite *make_ship(void);
    sfSprite *make_background(void);
    sfRenderWindow *create_window(unsigned int width, unsigned int height);
    sfSprite *make_ptr(void);
    sfSprite **game_sprites(sfRenderWindow *window);

    sfVector2f he_man_vect(sfRenderWindow *window);

    m_sprites_t *create_sprites(sfRenderWindow *window, int num);

#endif /* !TEK1_MY_H_ */
