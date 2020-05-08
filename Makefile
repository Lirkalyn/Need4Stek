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
		src/str_to_word_ar.c

OBJ		=	$(SRC:.c=.o)

CFLAGS  =       -I ./include/ -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
