/*
** EPITECH PROJECT, 2019
** update_score
** File description:
** update_score
*/

#include "my.h"

void update_score(graph *s)
{
    if (s->crash == false && s->clock->score && sfTime_asSeconds
    (sfClock_getElapsedTime(s->clock->score)) >= 1) {
        s->nb_score++;
        sfClock_restart(s->clock->score);
    }
    sfText_setString(s->score->str, my_strcat
    ("score : ", convert_int_str(s->nb_score)));
}
