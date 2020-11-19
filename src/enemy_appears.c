/*
** EPITECH PROJECT, 2019
** enemy_appears
** File description:
** enemy_appears
*/

#include "my.h"

void detect_touch(graph *s, sfVector2f obstacle, sfFloatRect bounds)
{
    if (s->player->pos.x + 50 * 2.2 <= obstacle.x &&
        s->player->pos.x + 50 * 2.2 + s->speed >= obstacle.x &&
        s->player->pos.y > obstacle.y - 560 * 2.3 / 8 &&
        s->player->pos.y < obstacle.y - 560 * 2.3 / 8 +
        2.44 * bounds.height)
        s->crash = true;
    if (s->player->pos.x + 50 * 2.2 >= obstacle.x &&
        s->player->pos.x + 50 * 2.2 <= obstacle.x + bounds.width &&
        !(s->player->pos.y < obstacle.y - 560 * 2.3 / 8) &&
        !(s->player->pos.y > obstacle.y - 560 * 2.3 / 8 + bounds.height))
        s->crash = true;
    if (s->player->pos.x + 50 * 2.2 >= obstacle.x &&
        s->player->pos.x + 50 * 2.2 <= obstacle.x + bounds.width &&
        s->player->pos.y <= obstacle.y + bounds.height &&
        s->player->pos.y > obstacle.y)
        s->crash = true;
}

void anim_enemy(graph *s, int rd)
{
    static bool rect = false;

    if (sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->clock->hawk)) >= 100 &&
    s->crash == false && s->win == false && s->scene->pause == false) {
        if (s->hawk[rd]->rect.left == 0)
            rect = false;
        if (s->hawk[rd]->rect.left < 641 - 641 / 3 && rect == false)
            s->hawk[rd]->rect.left += 641 / 4;
        else {
            s->hawk[rd]->rect.left -= 641 / 4;
            rect = true;
        }
        sfSprite_setTextureRect(s->hawk[rd]->sp, s->hawk[rd]->rect);
        sfClock_restart(s->clock->hawk);
    }
}

void enemy_appears(sfRenderWindow *window, graph *s)
{
    static float run = 0;
    sfFloatRect bounds;
    static int rd = 0;

    srand(time(NULL));
    if (s->hawk[0]->pos.x == WIDTH && s->hawk[1]->pos.x == WIDTH)
        rd = rand() % 2;
    bounds = sfSprite_getGlobalBounds(s->hawk[rd]->sp);
    anim_enemy(s, rd);
    if (s->hawk[rd]->pos.x == WIDTH)
        s->hawk[rd]->pos.y = rand() % 850;
    if (s->crash == false && s->win == false && s->scene->pause == false)
        s->hawk[rd]->pos.x -= 5;
    sfSprite_setPosition(s->hawk[rd]->sp, s->hawk[rd]->pos);
    if (s->hawk[rd]->rect.left > 0)
        bounds.height /= 2;
    detect_touch(s, s->hawk[rd]->pos, bounds);
    if (s->hawk[rd]->pos.x <= -bounds.width)
        s->hawk[rd]->pos.x = WIDTH;
    sfRenderWindow_drawSprite(window, s->hawk[rd]->sp, NULL);
}
