##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/loop.c		\
		src/init.c		\
		src/init_sprites.c	\
		src/init_textures.c	\
		src/move_background.c	\
		src/convert_int_str.c	\
		src/anim_player.c	\
		src/my_puterror.c	\
		src/read_map.c		\
		src/detect_floor.c	\
		src/display_map.c	\
		src/detect_if_pressed.c	\
		src/init_music.c	\
		src/update_score.c	\
		src/detect_crash.c	\
		src/manage_mouse.c	\
		src/init_values.c	\
		src/enemy_appears.c	\
		src/init_positions.c	\
		src/draw_sprites.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	-L ./lib/my -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system  -lcsfml-audio -lm

NAME	=	my_runner

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my re
