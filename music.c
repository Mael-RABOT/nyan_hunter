/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** music
*/

#include "include/my.h"

char *choose_music(int selector)
{
    if (selector < 0 || selector > 5)
        return (NULL);
    switch (selector) {
        case 0: return ("ress/nyan_music.ogg");
        case 1: return ("ress/nya_arigato.ogg");
        case 2: return ("ress/chad_music.ogg");
        case 3: return ("ress/suuu.ogg");
        case 4: return ("ress/rick.ogg");
    }
}

void launch_music(int music_id)
{
    if (music_id == 5)
        return;
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(choose_music(music_id));
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buff);
    sfSound_setVolume(sound, 40);
    sfSound_play(sound);
    sfSound_setLoop(sound, sfTrue);
}
