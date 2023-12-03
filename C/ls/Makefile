##
## EPITECH PROJECT, 2023
## Base Project
## File description:
## Makefile
##

CC = gcc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
NAME = my_ls
CFLAGS = -Wall -Wextra -I include
LDFLAGS = -L lib/my/ -lmy

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

unit_tests: $(OBJ)
	$(CC) -o unit_tests unit_tests/unit_tests.c $(OBJ) $(LDFLAGS) -lcriterion
	./unit_tests
