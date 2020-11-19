/*
** EPITECH PROJECT, 2019
** detect_if_pressed
** File description:
** detect_if_pressed
*/

#include "my.h"

void detect_end(graph *s)
{
    if (s->crash || s->win)
        sfMusic_stop(s->sound->escape);
}

void detect_if_pressed(graph *s)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == false)
        s->touch->space = false;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == false)
        s->touch->escape = false;
    detect_end(s);
}
