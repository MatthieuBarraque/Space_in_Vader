##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	main.c \
		level.c \
		my_putnbr.c \
		my_putchar.c 

CFLAGS	= 		-W -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

NAME	=	myhunter

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(CSFML)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean
	all
