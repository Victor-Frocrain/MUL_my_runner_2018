/*
** EPITECH PROJECT, 2019
** manage_mouse
** File description:
** manage_mouse
*/

#include "my.h"

void check_click(int i, graph *s)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && i == 1)
        s->exit = true;
    if (sfMouse_isButtonPressed(sfMouseLeft) && i == 0) {
        init_pos(s);
        init_values(s);
        sfClock_restart(s->clock->score);
        sfMusic_stop(s->sound->win);
        sfMusic_play(s->sound->escape);
        s->reset = true;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && i == 2) {
        init_pos(s);
        init_values(s);
        sfMusic_play(s->sound->escape);
        s->reset = true;
        s->main = false;
        sfMusic_stop(s->sound->main);
        sfMusic_play(s->sound->escape);
    }
}

void detect_position(graph *s, sfVector2i mouse)
{
    s->buttons[1]->pos.x = 230;
    s->buttons[1]->pos.y = 700;
    sfSprite_setPosition(s->buttons[1]->sp, s->buttons[1]->pos);
    for (int i = 1; i < 3 && s->main; i++) {
        if (mouse.x >= s->buttons[i]->pos.x &&
        mouse.x <= s->buttons[i]->pos.x + 646 * 0.6 &&
        mouse.y >= s->buttons[i]->pos.y &&
        mouse.y <= s->buttons[i]->pos.y + 410 / 2 * 0.6) {
            s->buttons[i]->rect.top = 410 / 2;
            check_click(i, s);
        }
        else
            s->buttons[i]->rect.top = 0;
        sfSprite_setTextureRect(s->buttons[i]->sp, s->buttons[i]->rect);
    }
}

void manage_mouse(sfRenderWindow *window, graph *s)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i < 3; i++) {
        s->buttons[i]->rect.width = 646;
        s->buttons[i]->rect.height = 410 / 2;
        s->buttons[i]->rect.left = 0;
        if (s->main)
            detect_position(s, mouse);
        else if (mouse.x >= s->buttons[i]->pos.x &&
        mouse.x <= s->buttons[i]->pos.x + 646 * 0.6 &&
        mouse.y >= s->buttons[i]->pos.y &&
        mouse.y <= s->buttons[i]->pos.y + 410 / 2 * 0.6) {
            s->buttons[i]->rect.top = 410 / 2;
            check_click(i, s);
        }
        else
            s->buttons[i]->rect.top = 0;
        sfSprite_setTextureRect(s->buttons[i]->sp, s->buttons[i]->rect);
    }
}
