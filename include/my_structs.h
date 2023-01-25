/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** my_structs
*/

#ifndef B_MUL_100_LYN_1_1_MYHUNTER_MAEL_RABOT_MY_STRUCTS_H_
    #define B_MUL_100_LYN_1_1_MYHUNTER_MAEL_RABOT_MY_STRUCTS_H_

    #include "SFML/System.h"
    #include "SFML/Graphics.h"

typedef struct nyan {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f vect;
    sfIntRect explo_rect;
    sfVector2f start;
    int is_outbound;
    int is_shot;
    int as_explode;
    int nyan_nb;
    int pos_nb;
} nyan_t;

typedef struct m_sprites {
    sfRenderWindow *window;
    sfSprite **s_list;
    nyan_t **n_list;
} m_sprites_t;

typedef struct score {
    int score;
    int last_score;
    int health;
} score_t;

typedef struct win_size {
    int width;
    int height;
} win_size_t;

typedef struct arguments {
    win_size_t size;
    int live;
    int nyan_number;
    int score_to_win;
    int music_id;
    int print;
} arguments_t;


#endif /* !B_MUL_100_LYN_1_1_MYHUNTER_MAEL_RABOT_MY_STRUCTS_H_ */
