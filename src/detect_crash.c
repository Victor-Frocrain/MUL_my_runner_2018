/*
** EPITECH PROJECT, 2019
** detect_crash
** File description:
** detect_crash
*/

#include "my.h"

void detect_win_up(graph *s, sfVector2f obstacle)
{
    if (s->player->pos.x + 50 * 2.2 >= obstacle.x &&
        s->player->pos.x + 50 * 2.2 <= obstacle.x + 164 * 0.5 &&
        !(s->player->pos.y < obstacle.y - 560 * 2.3 / 8) &&
        !(s->player->pos.y > obstacle.y - 560 * 2.3 / 8 + 164 * 0.5))
        s->win = true;
    if (s->player->pos.x + 50 * 2.2 / 2 >= obstacle.x &&
        s->player->pos.x + 50 * 2.2 / 2 <= obstacle.x + 164 * 0.5 &&
        !(s->player->pos.y < obstacle.y - 560 * 2.3 / 8) &&
        !(s->player->pos.y > obstacle.y - 560 * 2.3 / 8 + 164 * 0.5))
        s->win = true;
}

void detect_win(graph *s, sfVector2f obstacle)
{
    if (s->player->pos.x + 50 * 2.2 <= obstacle.x &&
        s->player->pos.x + 50 * 2.2 + s->speed >= obstacle.x &&
        s->player->pos.y > obstacle.y - 560 * 2.3 / 8 &&
        s->player->pos.y < obstacle.y - 560 * 2.3 / 8 +
        2 * (164 * 0.5))
        s->win = true;
    detect_win_up(s, obstacle);
    if (s->player->pos.x + 50 * 2.2 >= obstacle.x &&
        s->player->pos.x + 50 * 2.2 <= obstacle.x + 164 * 0.5 &&
        s->player->pos.y <= obstacle.y + 164 * 0.5 &&
        s->player->pos.y > obstacle.y)
        s->win = true;
    if (s->win && s->end == false) {
        sfMusic_play(s->sound->win);
        s->end = true;
    }
}

void detect_crash_up(graph *s, sfVector2f obstacle)
{
    if (s->player->pos.x + 50 * 2.2 >= obstacle.x &&
        s->player->pos.x + 50 * 2.2 <= obstacle.x + 164 * 0.5 &&
        !(s->player->pos.y < obstacle.y - 560 * 2.3 / 8) &&
        !(s->player->pos.y > obstacle.y - 560 * 2.3 / 8 + 164 * 0.5))
        s->crash = true;
    if (s->player->pos.x + 50 * 2.2 / 2 >= obstacle.x &&
        s->player->pos.x + 50 * 2.2 / 2 <= obstacle.x + 164 * 0.5 &&
        !(s->player->pos.y < obstacle.y - 560 * 2.3 / 8) &&
        !(s->player->pos.y > obstacle.y - 560 * 2.3 / 8 + 164 * 0.5))
        s->crash = true;
}

void detect_crash(graph *s, sfVector2f obstacle, bool solid)
{
    if (s->player->pos.y >= HEIGHT)
        s->crash = true;
    if (s->player->pos.x + 50 * 2.2 <= obstacle.x &&
        s->player->pos.x + 50 * 2.2 + s->speed >= obstacle.x &&
        s->player->pos.y > obstacle.y - 560 * 2.3 / 8 &&
        s->player->pos.y < obstacle.y - 560 * 2.3 / 8 +
        2 * (164 * 0.5))
        s->crash = true;
    if (solid == false)
        detect_crash_up(s, obstacle);
    if (s->player->pos.x + 50 * 2.2 >= obstacle.x &&
        s->player->pos.x + 50 * 2.2 <= obstacle.x + 164 * 0.5 &&
        s->player->pos.y <= obstacle.y + 164 * 0.5 &&
        s->player->pos.y > obstacle.y)
        s->crash = true;
    if (s->crash && s->end == false) {
        sfMusic_play(s->sound->crash);
        s->end = true;
    }
}
