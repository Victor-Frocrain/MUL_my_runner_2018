/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#ifndef MY_H_
#define MY_H_
#define MY_EXIT_ERROR 84
#define MY_EXIT_SUCCESS 0
#define SIZE_README 223
#define WIDTH 1920
#define HEIGHT 1080
#define NB_SPRITE 2
#define NB_TEX 2
#define ERROR "./my_runner: bad arguments: 0 given but 1 \
is required\nretry with -h\n"
#define MAX_LINES 10

typedef struct entity_t {
    sfTexture *tex;
    sfSprite *sp;
    sfVector2f pos;
    sfIntRect rect;
    char *file;
} entity;

typedef struct times_s {
    sfClock *player;
    sfClock *hawk;
    sfClock *jump;
    sfClock *move;
    sfClock *end;
    sfClock *score;
} times;

typedef struct touch_s {
    bool space;
    bool escape;
} touch;

typedef struct scene_s {
    bool end;
    bool pause;
} scene;

typedef struct sound_s {
    sfMusic *escape;
    sfMusic *main;
    sfMusic *crash;
    sfMusic *win;
} sound;

typedef struct text_s {
    sfText *str;
    sfFont *font;
    unsigned int size;
    sfVector2f pos;
} text;

typedef struct graph_s {
    entity *para[4];
    entity *player;
    entity *floor[3];
    entity *buttons[3];
    entity *menus[4];
    entity *hawk[2];
    text *score;
    times *clock;
    float speed;
    bool exit;
    bool begin;
    bool first_pos;
    bool jump;
    bool fall;
    bool reset;
    bool main;
    bool end;
    float land;
    float land2;
    bool crash;
    bool win;
    bool placed;
    bool placed2;
    touch *touch;
    char **map;
    sound *sound;
    scene *scene;
    int nb_score;
    int jump_time;
} graph;

sfIntRect create_rect(int left, int top, int width, int height);
void init_pictures(graph *s);
void draw_sprites(sfRenderWindow *window, graph *s);
void move_ship(sfRenderWindow *window, graph *s);
void move_mouse(sfRenderWindow *window, graph *sp);
void spray_ship(graph *s);
graph *init_graph(graph *s);
void init_rect(graph *s);
void init_textures(graph *s);
void init_pictures(graph *s);
bool detect_shoot(sfRenderWindow *window, sfVector2i mousei, graph *s);
int my_strcmp(char const *s1, char const *s2);
void destroy_ressources(graph *s);
void game_loop(sfRenderWindow *window, graph *s);
void display_life(graph *s);
void destroy_textures(graph *s);
void destroy_sprites(graph *s);
char *convert_int_str(int nb);
char *my_revstr(char *str);
void display_score(graph *s);
void read_best(graph *s);
int my_strlen(char *str);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
void my_put_nberror(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_memset(char *str, char c, int size);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *str1, char *str2);
void manage_pause(sfRenderWindow *window, graph *s);
void init_audio(graph *s);
void destroy_audio(graph *s);
void play_sounds(graph *s);
void score_scene(sfRenderWindow *window, graph *s);
void draw_sprites_score(sfRenderWindow *window, graph *s);
void main_scene(sfRenderWindow *window, graph *s);
void change_button_retry(sfRenderWindow *window, graph *s);
void change_button_play(sfRenderWindow *window, graph *s);
void change_button_exit(sfRenderWindow *window, graph *s,
float button_x, float button_y);
void check_if_retry(graph *s);
void change_button_resume(sfRenderWindow *window, graph *s);
void set_level(graph *s, float x, float y, int size);
void move_background(graph *s);
void anime_player(graph *s);
bool read_map(char **av, graph *s);
void display_player(sfRenderWindow *window, graph *s);
void my_puterror(char *str);
void detect_level(graph *s, sfFloatRect bound);
void detect_floor(graph *s, int i, int j, sfFloatRect bound);
void detect_crash(graph *s, sfVector2f obstacle, bool solid);
void prepare_read(sfRenderWindow *window, graph *s);
void detect_if_pressed(graph *s);
void init_music(graph *s);
void destroy_music(graph *s);
void update_score(graph *s);
void detect_win(graph *s, sfVector2f obstacle);
void manage_mouse(sfRenderWindow *window, graph *s);
void init_values(graph *s);
void init_pos(graph *s);
void enemy_appears(sfRenderWindow *window, graph *s);
void init_pos(graph *s);
void draw_menus(sfRenderWindow *window, graph *s);
void draw_sprites_game(sfRenderWindow *window, graph *s);
void draw_end(sfRenderWindow *window, graph *s);

#endif /* MY_H_ */
