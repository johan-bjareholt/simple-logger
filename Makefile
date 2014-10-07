
CC = gcc
FLAGS = -c -std=c11
INCLUDE = -I./src/
SRC = src/logger.c

all:
	mkdir -p obj
	$(CC) $(FLAGS) $(INCLUDE) $(SRC) -o obj/logger.o