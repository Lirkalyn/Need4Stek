##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.PHONY	:	$(NAME) clean fclean re

NAME	=	ai

SRC	=	src/main.c	\
		src/str_compare.c	\
		src/str_to_word_ar.c \
		src/display.c \
		src/dist.c \
		src/cmds.c \
		src/cmds_2.c \
		src/cmds_3.c \
		src/ai.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS  =       -I ./include/

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
