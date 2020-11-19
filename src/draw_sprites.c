/*
** EPITECH PROJECT, 2019
** draw_sprites
** File description:
** draw_sprites
*/

#include "my.h"

void draw_sprites_game(sfRenderWindow *window, graph *s)
{
    sfVector2f pos;

    pos.y = 0;
    for (int i = 0; i < 4; i++) {
        sfSprite_setPosition(s->para[i]->sp, s->para[i]->pos);
        sfRenderWindow_drawSprite(window, s->para[i]->sp, NULL);
        pos.x = s->para[i]->pos.x + WIDTH;
        sfSprite_setPosition(s->para[i]->sp, pos);
        sfRenderWindow_drawSprite(window, s->para[i]->sp, NULL);
    }
    prepare_read(window, s);
    sfSprite_setPosition(s->player->sp, s->player->pos);
    sfRenderWindow_drawSprite(window, s->player->sp, NULL);
    enemy_appears(window, s);
    if (s->crash == false)
        sfRenderWindow_drawText(window, s->score->str, NULL);
}

void draw_menus(sfRenderWindow *window, graph *s)
{
    if (s->main) {
        sfRenderWindow_drawSprite(window, s->menus[2]->sp, NULL);
        sfSprite_setPosition(s->buttons[2]->sp, s->buttons[2]->pos);
        manage_mouse(window, s);
        for (int i = 1; i < 3; i++)
            sfRenderWindow_drawSprite(window, s->buttons[i]->sp, NULL);
    }
    else if (s->scene->pause) {
        draw_sprites_game(window, s);
        sfRenderWindow_drawSprite(window, s->menus[3]->sp, NULL);
    }
}

void draw_end(sfRenderWindow *window, graph *s)
{
    sfVector2f pos;

    if (s->win)
        sfRenderWindow_drawSprite(window, s->menus[0]->sp, NULL);
    else if (s->crash) {
        draw_sprites_game(window, s);
        sfRenderWindow_drawSprite(window, s->menus[1]->sp, NULL);
    }
    sfText_setCharacterSize(s->score->str, 70);
    pos.x = WIDTH / 3 + 115;
    pos.y = HEIGHT - HEIGHT / 3 - 50;
    sfText_setPosition(s->score->str, pos);
    sfRenderWindow_drawText(window, s->score->str, NULL);
    manage_mouse(window, s);
    for (int i = 0; i < 2; i++) {
        sfSprite_setPosition(s->buttons[i]->sp, s->buttons[i]->pos);
        sfRenderWindow_drawSprite(window, s->buttons[i]->sp, NULL);
    }
}
