##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =   $(wildcard *.c)

OBJ     =   $(SRC:.c=.o)

NAME    =   libmy.a

CFLAGS  +=  -Wall -Wextra -I ../../include

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re: fclean all
