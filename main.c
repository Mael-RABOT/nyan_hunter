/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** main.c
*/

#include "include/my.h"

int my_getnbr(const char *buffer)
{
    int i = 0;
    int res = 0;
    int mult = 1;
    int is_neg = (buffer[0] == '-') ? 1 : 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    for (int ite = is_neg; ite < i; ite++) {
        res += (buffer[i - ite - 1 + is_neg] - 48) * mult;
        mult = mult * 10;
    }
    return (is_neg == 1) ? -res : res;
}

int print_rules(int nb, char **arguments)
{
    int number = 1;
    if (nb >= 2) {
        if (arguments[1][0] == '-' && arguments[1][1] == 'h') {
            int fd = open("rules.txt", O_RDONLY);
            char buff[30000];
            read(fd, buff, 29999);
            my_printf("%s", buff);
            return (42);
        } else
            number = my_getnbr(arguments[1]);
    }
    if (number < 0 || number > 4)
        number = 1;
    return (number);
}

char *choose_music(int selector)
{
    if (selector < 0 || selector > 4)
        return (NULL);
    switch (selector) {
        case 0: return ("ress/nya_arigato.ogg");
        case 1: return ("ress/nyan_music.ogg");
        case 2: return ("ress/chad_music.ogg");
        case 3: return ("ress/suuu.ogg");
        case 4: return ("ress/rick.ogg");
    }
}

int main(int ac, char **av)
{
    int music = print_rules(ac, av);
    if (music == 42)
        return (EXIT_SUCCESS);
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(choose_music(music));
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buff);
    sfSound_setVolume(sound, 40);
    sfSound_play(sound);
    sfSound_setLoop(sound, sfTrue);
    srand(time(NULL));
    sfRenderWindow *window = create_window(1920, 1080);
    sfEvent event;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    menu(window, event);
    sfVector2f vect = {400, 400};
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
