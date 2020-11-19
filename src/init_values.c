/*
** EPITECH PROJECT, 2019
** init_values
** File description:
** init_values
*/

#include "my.h"

void init_values2(graph *s)
{
    s->jump = false;
    s->fall = false;
    s->crash = false;
    s->placed = false;
    s->placed2 = false;
    s->begin = true;
    s->first_pos = true;
    s->touch->space = false;
    s->touch->escape = false;
    s->scene->end = false;
    s->scene->pause = false;
    s->win = false;
    s->end = false;
    for (int i = 0; i < 2; i++) {
        s->hawk[i]->rect.top = 0;
        s->hawk[i]->rect.left = 0;
        s->hawk[i]->rect.width = 641 / 4;
        s->hawk[i]->rect.height = 110;
    }
}

void init_values(graph *s)
{
    s->speed = 3;
    s->player->rect.top = 0;
    s->player->rect.left = 0;
    s->player->rect.width = 50;
    s->player->rect.height = 560 / 8;
    s->clock->player = sfClock_create();
    s->clock->move = sfClock_create();
    s->player->pos.x = 30;
    s->player->pos.y = 0;
    s->score->size = 50;
    s->score->pos.x = 30;
    s->score->pos.y = 10;
    s->jump_time = 0;
    init_values2(s);
}
