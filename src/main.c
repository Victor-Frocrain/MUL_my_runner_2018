/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int read_help(char *str)
{
    int fd = -1;
    char *buff;

    if (str && my_strcmp(str, "-h") == 0)
        fd = open("README", O_RDONLY);
    else if (str && my_strcmp(str, "-s") == 0)
        fd = open("story", O_RDONLY);
    if (fd < 0)
        return (MY_EXIT_ERROR);
    buff = malloc(sizeof(char) * SIZE_README);
    if (buff == NULL) {
        close(fd);
        return (MY_EXIT_ERROR);
    }
    read(fd, buff, SIZE_README);
    write(1, buff, SIZE_README);
    close(fd);
    free(buff);
    return (MY_EXIT_SUCCESS);
}

bool parse_errors(int ac)
{
    if (ac != 2) {
        my_puterror("./my_runner: bad arguments: ");
        my_put_nberror(ac - 1);
        my_puterror(" given but 1 is required\nretry with -h\n");
        return (false);
    }
    return (true);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window;
    graph *s;

    if (parse_errors(ac) == false)
        return (MY_EXIT_ERROR);
    if (ac == 2 && (my_strcmp(av[1], "-h") == 0 || my_strcmp(av[1], "-s") == 0))
        return (read_help(av[1]));
    s = init_graph(s);
    if (read_map(av, s) == false) {
        destroy_ressources(s);
        return (MY_EXIT_ERROR);
    }
    window = sfRenderWindow_create
    (mode, "ASSASSIN'S CREED ESCAPE", sfResize | sfClose, NULL);
    if (!window)
        return (MY_EXIT_ERROR);
    init_textures(s);
    init_pictures(s);
    game_loop(window, s);
    return (MY_EXIT_SUCCESS);
}
