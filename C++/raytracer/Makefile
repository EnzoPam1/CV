##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -I src
LDFLAGS = -lconfig++

SRC := $(shell find src -type f -name '*.cpp')
OBJ := $(SRC:.cpp=.o)

BIN := raytracer

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)

re: fclean all

.PHONY: all clean fclean re
