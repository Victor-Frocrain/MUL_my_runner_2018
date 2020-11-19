/*
** EPITECH PROJECT, 2018
** loop
** File description:
** loop
*/

#include "my.h"

void check_pause(graph *s)
{
    if (s->touch->escape == false && s->win == false &&
    s->crash == false && s->main == false &&
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (s->scene->pause == false) {
            s->scene->pause = true;
            s->jump_time = sfTime_asMilliseconds
            (sfClock_getElapsedTime(s->clock->jump));
        }
        else {
            s->scene->pause = false;
            sfClock_restart(s->clock->jump);
        }
        s->touch->escape = true;
    }
}

void game_actions(sfRenderWindow *window, graph *s)
{
    sfRenderWindow_clear(window, sfBlack);
    detect_if_pressed(s);
    check_pause(s);
    if (s->main || s->scene->pause)
        draw_menus(window, s);
    else if (s->crash == false && s->win == false &&
    s->scene->pause == false) {
        if (s->begin) {
            s->clock->score = sfClock_create();
            s->nb_score = 0;
            s->begin = false;
        }
        move_background(s);
        anime_player(s);
        update_score(s);
        draw_sprites_game(window, s);
    }
    else if (s->win == true || s->crash == true)
        draw_end(window, s);
    sfRenderWindow_display(window);
}

void check_close(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
}

void game_loop(sfRenderWindow *window, graph *s)
{
    sfEvent event;

    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 60);
    s->reset = true;
    s->main = true;
    sfMusic_play(s->sound->main);
    while (sfRenderWindow_isOpen(window) && s->exit == false) {
        check_close(window, event);
        game_actions(window, s);
    }
    destroy_ressources(s);
    sfRenderWindow_destroy(window);
}
