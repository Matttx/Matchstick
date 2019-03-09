##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for CPE_matchstick_bootstrap_2018
##

NAME			=		matchstick

CC				=		gcc

RM				=		rm -f

SRC				=		main.c							\
						print_game_board.c				\
						my_rows.c						\
						informations.c					\
						error_line_matches.c			\
						my_put_nbr.c					\
						game.c							\
						my_putchar.c					\
						remove_matches.c				\
						ai.c							\

OBJ             =		$(SRC:.c=.o)

CFLAGS	=	-I "./include" -g3
CFLAGS	+=	 -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lncurses

clean: clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.o

re:	fclean all

sweet: all clean
