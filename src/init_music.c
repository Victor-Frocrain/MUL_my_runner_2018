/*
** EPITECH PROJECT, 2019
** init_music
** File description:
** init_music
*/

#include "my.h"

void init_music(graph *s)
{
    s->sound->escape = sfMusic_createFromFile("sounds/escape.ogg");
    s->sound->main = sfMusic_createFromFile("sounds/main.ogg");
    s->sound->crash = sfMusic_createFromFile("sounds/crash.ogg");
    s->sound->win = sfMusic_createFromFile("sounds/win.ogg");
    sfMusic_setLoop(s->sound->escape, true);
}

void destroy_music(graph *s)
{
    sfMusic_destroy(s->sound->escape);
    sfMusic_destroy(s->sound->main);
    sfMusic_destroy(s->sound->crash);
    sfMusic_destroy(s->sound->win);
    free(s->sound);
}
