##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRC = src/my_printf.c \
	src/handlers.c \
	src/base_converters.c \
	src/process_functions.c \
	src/process_functions_two.c \
	src/my_putchar.c \
	src/my_putstr.c \
	src/my_put_nbr.c \
	src/my_strlen.c \
	src/my_strcpy.c \

OBJ = $(SRC:.c=.o)

TEST_SRC = tests/tests_my_printf.c
TEST_OBJ = $(TEST_SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

$(TEST_OBJ): $(NAME)

unit_tests: fclean $(OBJ) $(TEST_OBJ)
	$(CC) -o unit_tests $(OBJ) $(TEST_OBJ) -lcriterion -L. -lmy

tests_run: unit_tests
	./unit_tests
