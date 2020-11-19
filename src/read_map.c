/*
** EPITECH PROJECT, 2018
** read_map
** File description:
** read_map
*/

#include "my.h"
#include "get_next_line.h"

bool check_winblocks(graph *s)
{
    int j = 0;
    int nb = 0;

    for (int i = 0; s->map[i];) {
        if (s->map[i][j] && s->map[i][j] == 'Z')
            nb++;
        if (s->map[i][j] && s->map[i][j + 1])
            j++;
        else {
            i++;
            j = 0;
        }
    }
    if (nb == 0) {
        my_puterror("invalid map.\nIt must have at least one Z.\n");
        return (false);
    }
    return (true);
}

bool analyse_map(graph *s)
{
    int j = 0;

    for (int i = 0; s->map[i];) {
        if (s->map[i][j] &&
        s->map[i][j] != 'X' && s->map[i][j] != ' ' &&
        s->map[i][j] != '\n' && s->map[i][j] != 'Y' &&
        s->map[i][j] != 'Z') {
            my_puterror("invalid map.\n");
            return (false);
        }
        if (s->map[i][j] && s->map[i][j + 1])
            j++;
        else {
            i++;
            j = 0;
        }
    }
    return (check_winblocks(s));
}

bool read_map(char **av, graph *s)
{
    int i = 0;
    int fd;
    char *str = NULL;

    fd = open(av[1], O_RDONLY);
    if (fd < 0) {
        my_puterror(av[1]);
        my_puterror(" is not a file.\n");
        return (false);
    }
    str = get_next_line(fd);
    for (i = 0; str && i < MAX_LINES; i++) {
        s->map[i] = str;
        str = get_next_line(fd);
    }
    if (i != MAX_LINES || str != NULL) {
        my_puterror("invalid map size: it must have 10 lines.\n");
        return (false);
    }
    return (analyse_map(s));
}
