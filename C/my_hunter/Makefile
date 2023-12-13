##
## EPITECH PROJECT, 2023
## Base Project
## File description:
## Makefile
##

CC = gcc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
NAME = my_hunter
CFLAGS = -Wall -Wextra -I include
LDFLAGS = -L lib/my/ -lmy \
          -lsfml-graphics -lsfml-window -lsfml-system \
          -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
		  -lsfml-audio

all: libmy.a $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

libmy.a:
	make -C lib/my/

clean:
	rm -fv $(OBJ)
	rm -fv src/*~
	rm -fv include/*~
	rm -fv *~
	make -C lib/my/ clean

fclean: clean
	rm -fv $(NAME)
	make -C lib/my/ fclean

re: fclean all

tests_run: unit_tests
	./unit_tests
