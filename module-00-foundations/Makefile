# Makefile for Module 00 Exercises

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../../common

.PHONY: all clean

all: ex1_pointers.out ex2_memory_layout.out

ex1_pointers.out: exercises/ex1_pointers.c
	$(CC) $(CFLAGS) -o $@ $^

ex2_memory_layout.out: exercises/ex2_memory_layout.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.out
