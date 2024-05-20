##
## EPITECH PROJECT, 2023
## Base Project
## File description:
## Makefile
##

CC = gcc
SRC = $(wildcard src/*.c) $(shell find src/collisions -type f -name '*.c') \
      $(shell find src/draw -type f -name '*.c') \
      $(shell find src/events -type f -name '*.c') \
      $(shell find src/file_manipulation -type f -name '*.c') \
      $(shell find src/structures -type f -name '*.c') \
      $(shell find src/utilities -type f -name '*.c')
OBJ = $(SRC:.c=.o)
NAME = my_radar
CFLAGS = -Wall -Wextra -I include -I include/building -I \
	include/building/simulation
LDFLAGS = -L lib/my/ -lmy -lcsfml-graphics -lcsfml-system -lm

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
