/*
** EPITECH PROJECT, 2019
** init_positions
** File description:
** init_positions
*/

#include "my.h"

void init_pos2(graph *s)
{
    for (int i = 0; i < 2; i++)
        s->buttons[i]->pos.y = HEIGHT - 300;
    s->buttons[0]->pos.x = 250;
    s->buttons[1]->pos.x = WIDTH - 250 - 646 * 0.6;
    s->buttons[2]->pos.x = 230;
    s->buttons[2]->pos.y = 520;
}

void init_pos(graph *s)
{
    for (int i = 0; i < 4; i++) {
        s->para[i]->pos.x = 0;
        s->para[i]->pos.y = 0;
    }
    for (int i = 0; i < 3; i++) {
        s->floor[i]->pos.x = 0;
        s->floor[i]->pos.y = 0;
    }
    for (int i = 0; i < 3; i++) {
        s->menus[i]->pos.x = 0;
        s->menus[i]->pos.y = 0;
    }
    for (int i = 0; i < 2; i++)
        s->hawk[i]->pos.x = WIDTH;
    sfText_setPosition(s->score->str, s->score->pos);
    init_pos2(s);
}
