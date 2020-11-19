/*
** EPITECH PROJECT, 2018
** init_sprites
** File description:
** init_sprites
*/

#include "my.h"

void init_scales(graph *s)
{
    sfVector2f p_scale = {2.5, 2.5};
    sfVector2f l_scale = {0.5, 0.5};
    sfVector2f b_scale = {0.6, 0.6};
    sfVector2f h_scale = {0.6, 0.6};

    for (int i = 0; i < 3; i++)
        sfSprite_setScale(s->floor[i]->sp, l_scale);
    for (int i = 0; i < 3; i++)
        sfSprite_setScale(s->buttons[i]->sp, b_scale);
    sfSprite_setScale(s->player->sp, p_scale);
    for (int i = 0; i < 2; i++)
        sfSprite_setScale(s->hawk[i]->sp, h_scale);
}

void create_sprite(graph *s)
{
    int i = 0;

    for (i = 0; i < 4; i++)
        s->para[i]->sp = sfSprite_create();
    s->player->sp = sfSprite_create();
    for (i = 0; i < 2; i++)
        s->hawk[i]->sp = sfSprite_create();
    for (i = 0; i < 3; i++)
        s->floor[i]->sp = sfSprite_create();
    for (i = 0; i < 3; i++)
        s->buttons[i]->sp = sfSprite_create();
    for (i = 0; i < 4; i++)
        s->menus[i]->sp = sfSprite_create();
}

void destroy_sprites(graph *s)
{
    for (int i = 0; i < 4; i++)
        sfSprite_destroy(s->para[i]->sp);
    sfSprite_destroy(s->player->sp);
    for (int i = 0; i < 2; i++)
        sfSprite_destroy(s->hawk[i]->sp);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(s->floor[i]->sp);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(s->buttons[i]->sp);
    for (int i = 0; i < 4; i++)
        sfSprite_destroy(s->menus[i]->sp);
}

void init_pictures(graph *s)
{
    create_sprite(s);
    for (int i = 0; i < 4; i++)
        sfSprite_setTexture(s->para[i]->sp, s->para[i]->tex, sfFalse);
    sfSprite_setTexture(s->player->sp, s->player->tex, sfFalse);
    for (int i = 0; i < 2; i++)
        sfSprite_setTexture(s->hawk[i]->sp, s->hawk[i]->tex, sfFalse);
    for (int i = 0; i < 3; i++)
        sfSprite_setTexture(s->floor[i]->sp, s->floor[i]->tex, sfFalse);
    for (int i = 0; i < 3; i++)
        sfSprite_setTexture(s->buttons[i]->sp, s->buttons[i]->tex, sfFalse);
    for (int i = 0; i < 4; i++)
        sfSprite_setTexture(s->menus[i]->sp, s->menus[i]->tex, sfFalse);
    init_scales(s);
}
