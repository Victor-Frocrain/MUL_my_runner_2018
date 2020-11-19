/*
** EPITECH PROJECT, 2019
** detect_floor
** File description:
** detect_floor
*/

#include "my.h"

void detect_level(graph *s, sfFloatRect bound)
{
    if (s->player->pos.x + 50 * 2.3 >= s->floor[0]->pos.x &&
    s->player->pos.x + 50 * 2.3 < s->floor[0]->pos.x + bound.width &&
    s->placed == false) {
        s->land = s->floor[0]->pos.y - 560 * 2.3 / 8;
        s->placed = true;
    }
    if (s->player->pos.x >= s->floor[0]->pos.x &&
    s->player->pos.x < s->floor[0]->pos.x + bound.width &&
    s->placed2 == false) {
        s->land2 = s->floor[0]->pos.y - 560 * 2.3 / 8;
        s->placed2 = true;
    }
}

void detect_floor(graph *s, int i, int j, sfFloatRect bound)
{
    if (s->first_pos == true && s->player->pos.x >= s->floor[0]->pos.x &&
    s->player->pos.x < s->floor[0]->pos.x + bound.width) {
        s->first_pos = false;
        s->player->pos.y = s->floor[0]->pos.y - 560 * 2.3 / 8;
    }
    else if (s->player->pos.x >= s->floor[0]->pos.x &&
        s->player->pos.x < s->floor[0]->pos.x + bound.width &&
        s->player->pos.y < s->floor[0]->pos.y - 560 * 2.3 / 8 &&
        s->player->pos.y < s->land && s->player->pos.y < s->land2)
        s->fall = true;
    detect_crash(s, s->floor[0]->pos, true);
    detect_level(s, bound);
}
