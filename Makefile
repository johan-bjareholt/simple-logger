
CC = gcc
CXX = g++
FLAGS = -g
SRC = logger.c
OUT = logger.o

all:
	$(CC) -std=c11 $(FLAGS) $(INCLUDE) $(SRC) -c -o $(OUT)

cpp:
	$(CXX) -std=c++11 $(FLAGS) $(INCLUDE) $(SRC) -c -o $(OUT)

clean:
	rm $(OUT)

.PHONY: all cpp clean
