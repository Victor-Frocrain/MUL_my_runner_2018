/*
** EPITECH PROJECT, 2018
** init
** File description:
** init
*/

#include "my.h"

void alloc_entities(graph *s)
{
    for (int i = 0; i < 4; i++)
        s->para[i] = malloc(sizeof(entity));
    for (int i = 0; i < 3; i++)
        s->floor[i] = malloc(sizeof(entity));
    for (int i = 0; i < 3; i++)
        s->buttons[i] = malloc(sizeof(entity));
    for (int i = 0; i < 4; i++)
        s->menus[i] = malloc(sizeof(entity));
    for (int i = 0; i < 2; i++)
        s->hawk[i] = malloc(sizeof(entity));
}

void init_text(graph *s)
{
    s->score->font = sfFont_createFromFile("font/assassin.ttf");
    sfText_setFont(s->score->str, s->score->font);
    sfText_setCharacterSize(s->score->str, s->score->size);
}

graph *init_graph(graph *s)
{
    s = malloc(sizeof(graph));
    s->player = malloc(sizeof(entity));
    s->clock = malloc(sizeof(times));
    s->touch = malloc(sizeof(touch));
    s->scene = malloc(sizeof(scene));
    s->sound = malloc(sizeof(sound));
    s->score = malloc(sizeof(text));
    s->map = malloc(sizeof(char *) * (MAX_LINES + 1));
    s->clock->jump = sfClock_create();
    s->clock->hawk = sfClock_create();
    s->score->str = sfText_create();
    alloc_entities(s);
    init_pos(s);
    init_values(s);
    init_music(s);
    init_text(s);
    return (s);
}

void destroy_ressources(graph *s)
{
    destroy_sprites(s);
    destroy_textures(s);
    destroy_music(s);
    sfClock_destroy(s->clock->jump);
    sfClock_destroy(s->clock->player);
    sfClock_destroy(s->clock->move);
    sfClock_destroy(s->clock->hawk);
    sfText_destroy(s->score->str);
    free(s->player);
    free(s->clock);
    free(s->touch);
    free(s->scene);
    free(s->map);
    free(s->score);
    free(s);
}
