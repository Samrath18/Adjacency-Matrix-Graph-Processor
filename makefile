# Define the compiler and flags
CC = gcc -Wall -std=c99 -pedantic
RM = rm

default: all

all: a4

a4: main.c graph_functions.c graph.h
	$(CC) -o a4 main.c graph_functions.c

clean:
	$(RM) a4