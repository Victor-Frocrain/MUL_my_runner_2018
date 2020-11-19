/*
** EPITECH PROJECT, 2018
** move_background
** File description:
** move_background
*/

#include "my.h"

float set_speed(graph *s, int i)
{
    if (i == 0)
        return (s->speed / 4.5);
    if (i == 1)
        return (s->speed / 3);
    if (i == 2)
        return (s->speed / 1.5);
    if (i == 3)
        return (s->speed);
    return (0);
}

void move_background(graph *s)
{
    for (int i = 0; i < 4; i++) {
        if (s->para[i]->pos.x <= -WIDTH)
            s->para[i]->pos.x = 0;
        if (s->crash == false && s->scene->pause == false)
            s->para[i]->pos.x -= set_speed(s, i);
    }
}
