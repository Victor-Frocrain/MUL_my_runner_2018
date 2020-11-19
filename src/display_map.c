/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** display_map
*/

#include "my.h"

int display_obstacles2(sfRenderWindow *window, graph *s, int i, int j)
{
    sfFloatRect bound;

    if (s->map[i][j] && s->map[i][j] == 'Z') {
        sfSprite_setPosition(s->floor[2]->sp, s->floor[2]->pos);
        sfRenderWindow_drawSprite(window, s->floor[2]->sp, NULL);
        bound = sfSprite_getGlobalBounds(s->floor[2]->sp);
        detect_win(s, s->floor[2]->pos);
    }
    return (0);
}

int display_obstacles(sfRenderWindow *window, graph *s, int i, int j)
{
    sfFloatRect bound;
    int blocs = 0;

    switch (s->map[i][j]) {
    case 'X':
        sfSprite_setPosition(s->floor[0]->sp, s->floor[0]->pos);
        sfRenderWindow_drawSprite(window, s->floor[0]->sp, NULL);
        bound = sfSprite_getGlobalBounds(s->floor[0]->sp);
        if (s->player->pos.x >= s->floor[0]->pos.x &&
            s->player->pos.x < s->floor[0]->pos.x + bound.width)
            blocs++;
        detect_floor(s, i, j, bound);
        break;
    case 'Y':
        sfSprite_setPosition(s->floor[1]->sp, s->floor[1]->pos);
        sfRenderWindow_drawSprite(window, s->floor[1]->sp, NULL);
        detect_crash(s, s->floor[1]->pos, false);
        break;
    }
    return (blocs + display_obstacles2(window, s, i, j));
}

void display_map(sfRenderWindow *window, graph *s, float run)
{
    int j = 0;
    int blocs = 0;

    for (int i = 0; s->map[i];) {
        for (int k = 0; k < 3; k++) {
            s->floor[k]->pos.x = 164 * 0.5 * j - run;
            s->floor[k]->pos.y = HEIGHT / 10 + 82 + 164 * 0.5 * i;
        }
        blocs += display_obstacles(window, s, i, j);
        if (s->map[i][j + 1])
            j++;
        else {
            j = 0;
            i++;
        }
    }
    if (blocs == 0) {
        s->land2 = WIDTH;
        s->fall = true;
    }
}

void prepare_read(sfRenderWindow *window, graph *s)
{
    static float run = 0;

    s->placed = false;
    s->placed2 = false;
    if (s->crash == false && s->win == false && s->reset == false &&
        s->scene->pause == false)
        run += s->speed;
    else if (s->win || s->reset) {
        run = 0;
        s->reset = false;
    }
    display_map(window, s, run);
}
