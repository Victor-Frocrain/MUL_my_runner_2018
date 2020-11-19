/*
** EPITECH PROJECT, 2018
** init_textures
** File description:
** init_textures
*/

#include "my.h"

void init_filepath2(graph *s)
{
    for (int i = 0; i < 3; i++)
        s->buttons[i]->file = malloc(sizeof(char) * 18);
    s->buttons[0]->file = my_strcpy(s->buttons[0]->file, "pictures/retry.png");
    s->buttons[1]->file = my_strcpy(s->buttons[1]->file, "pictures/exit.png");
    s->buttons[2]->file = my_strcpy(s->buttons[2]->file, "pictures/play.png");
    for (int i = 0; i < 4; i++)
        s->menus[i]->file = malloc(sizeof(char) * 18);
    s->menus[0]->file = my_strcpy(s->menus[0]->file, "pictures/win.png");
    s->menus[1]->file = my_strcpy(s->menus[1]->file, "pictures/loose.png");
    s->menus[2]->file = my_strcpy(s->menus[2]->file, "pictures/main.png");
    s->menus[3]->file = my_strcpy(s->menus[3]->file, "pictures/pause.png");
    for (int i = 0; i < 2; i++)
        s->hawk[i]->file = malloc(sizeof(char) * 17);
    s->hawk[0]->file = my_strcpy(s->hawk[0]->file, "pictures/mob.png");
    s->hawk[1]->file = my_strcpy(s->hawk[1]->file, "pictures/mob2.png");
}

void init_filepath(graph *s)
{
    for (int i = 0; i < 4; i++)
        s->para[i]->file = malloc(sizeof(char) * 26);
    s->para[0]->file = my_strcpy(s->para[0]->file, "pictures/backs/sky.png");
    s->para[1]->file = my_strcpy(s->para[1]->file, "pictures/backs/back.png");
    s->para[2]->file = my_strcpy(s->para[2]->file, "pictures/backs/middle.png");
    s->para[3]->file = my_strcpy(s->para[3]->file, "pictures/backs/front.png");
    s->player->file = malloc(sizeof(char) * 18);
    s->player->file = my_strcpy(s->player->file, "pictures/hero.png");
    for (int i = 0; i < 3; i++)
        s->floor[i]->file = malloc(sizeof(char) * 25);
    s->floor[0]->file = my_strcpy(s->floor[0]->file,
    "pictures/underground.png");
    s->floor[1]->file = my_strcpy(s->floor[1]->file, "pictures/cactus.png");
    s->floor[2]->file = my_strcpy(s->floor[2]->file, "pictures/abstergo.png");
    init_filepath2(s);
}

void init_textures(graph *s)
{
    int i = 0;

    init_filepath(s);
    for (i = 0; i < 4 && s->para[i]->file; i++)
        s->para[i]->tex = sfTexture_createFromFile
        (s->para[i]->file, NULL);
    s->player->tex = sfTexture_createFromFile
    (s->player->file, NULL);
    for (i = 0; i < 2; i++)
        s->hawk[i]->tex = sfTexture_createFromFile
        (s->hawk[i]->file, NULL);
    for (i = 0; i < 3 && s->floor[i]->file; i++)
        s->floor[i]->tex = sfTexture_createFromFile
        (s->floor[i]->file, NULL);
    for (i = 0; i < 3 && s->buttons[i]->file; i++)
        s->buttons[i]->tex = sfTexture_createFromFile
        (s->buttons[i]->file, NULL);
    for (i = 0; i < 4 && s->menus[i]->file; i++)
        s->menus[i]->tex = sfTexture_createFromFile
        (s->menus[i]->file, NULL);
}

void destroy_textures(graph *s)
{
    for (int i = 0; i < 4; i++)
        sfTexture_destroy(s->para[i]->tex);
    for (int i = 0; i < 3; i++)
        sfTexture_destroy(s->floor[i]->tex);
    for (int i = 0; i < 3; i++)
        sfTexture_destroy(s->buttons[i]->tex);
    for (int i = 0; i < 4; i++)
        sfTexture_destroy(s->menus[i]->tex);
    sfTexture_destroy(s->player->tex);
    for (int i = 0; i < 2; i++)
        sfTexture_destroy(s->hawk[i]->tex);
}
