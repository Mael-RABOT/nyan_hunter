/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** main.c
*/

#include "include/my.h"

void print_man(void)
{
    struct stat sb;
    int fd = open("README.txt", O_RDONLY);
    int size = 3000;
    char buff[size + 1];
    read(fd, buff, size);
    my_printf("%s", buff);
}

void assign_data_bis(char const *arg, char *value, arguments_t **arguments)
{
    switch (arg[1]) {
        case 'S':
            (*arguments)->score_to_win = (int) my_getnbr_parser(value);
            break;
        case 'M':
            (*arguments)->music_id = (int) my_getnbr_parser(value);
            break;
    }
}

void assign_data(char const *arg, char *value, arguments_t **arguments)
{
    if (arg[0] != '-')
        return;
    switch (arg[1]) {
        case 'h':
            (*arguments)->print = 1;
            break;
        case 'H':
            (*arguments)->size.height = (int) my_getnbr_parser(value);
            break;
        case 'W':
            (*arguments)->size.width = (int) my_getnbr_parser(value);
            break;
        case 'E':
            (*arguments)->nyan_number = (int) my_getnbr_parser(value);
            break;
        case 'L':
            (*arguments)->live = (int) my_getnbr_parser(value);
            break;
    }
    assign_data_bis(arg, value, arguments);
}

arguments_t *parser(int ac, char **av)
{
    arguments_t *res;
    res = malloc(sizeof(arguments_t));
    res->size.width = 0;
    res->size.height = 0;
    res->nyan_number = 0;
    res->live = 0;
    res->score_to_win = 0;
    res->music_id = 0;
    res->print = 0;
    for (int i = 0; i < ac - 1; i++)
        assign_data(av[i], av[i + 1], &res);
    res->print = (av[ac - 1][0] == '-' && av[ac - 1][1] == 'h')
        ? 1 : res->print;
    return (res);
}

int main(int ac, char **av)
{
    arguments_t *arguments = parser(ac, av);
    if (arguments->print) {
        print_man();
        return (EXIT_SUCCESS);
    }
    launch_music(arguments->music_id);
    srand(time(NULL));
    sfRenderWindow *window = create_window(arguments);
    sfEvent event;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    menu(window, event, arguments);
    sfRenderWindow_destroy(window);
    return (EXIT_SUCCESS);
}
