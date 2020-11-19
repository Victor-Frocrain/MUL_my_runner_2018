/*
** EPITECH PROJECT, 2018
** anim_player
** File description:
** anime player
*/

#include "my.h"

void player_land(graph *s, float land)
{
    if (land - s->player->pos.y > 10)
        s->player->pos.y += 5;
    else if (land - s->player->pos.y <= 10 &&
    land - s->player->pos.y > 0) {
        s->jump = false;
        s->fall = false;
        s->player->pos.y += land - s->player->pos.y;
        s->jump_time = 0;
    }
}

void player_jump(graph *s)
{
    if (sfTime_asMilliseconds
        (sfClock_getElapsedTime(s->clock->jump)) + s->jump_time < 700)
        s->player->pos.y -= 7;
    else if (s->jump && sfTime_asMilliseconds
        (sfClock_getElapsedTime(s->clock->jump)) + s->jump_time > 750)
        player_land(s, s->land);
    else if (s->fall && sfTime_asMilliseconds
        (sfClock_getElapsedTime(s->clock->jump)) + s->jump_time > 750)
        player_land(s, s->land2);
}

void anime_player(graph *s)
{
    if (sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->clock->player)) >= 100 &&
    s->crash == false && s->jump == false && s->fall == false) {
        if (s->player->rect.top < 550 - 70)
            s->player->rect.top += 70;
        else
            s->player->rect.top = 0;
        sfClock_restart(s->clock->player);
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) && s->jump == false &&
    s->touch->space == false && s->crash == false && s->fall == false) {
        s->jump = true;
        s->touch->space = true;
        s->jump_time = 0;
        sfClock_restart(s->clock->jump);
    }
    if ((s->jump == true || s->fall == true) && s->crash == false)
        player_jump(s);
    sfSprite_setTextureRect(s->player->sp, s->player->rect);
}
