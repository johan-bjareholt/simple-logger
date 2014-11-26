
CC = gcc
FLAGS = -c -std=c11
INCLUDE = -I./src/ -I./include/
SRC = src/logger.c

all:
	mkdir -p obj
	$(CC) $(FLAGS) $(INCLUDE) $(SRC) -o obj/logger.o

clean:
	rm -r obj
