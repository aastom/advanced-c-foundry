# Makefile for Module 01

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../../common -I. -O2
LDFLAGS = -lm

.PHONY: all clean

all: example_arena.out exercise.out

# The example is self-contained
example_arena.out: example_arena.c example_arena.h
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# The exercise requires the common utils
exercise.out: exercise.c ../../common/utils.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run_example:
	./example_arena.out

run_exercise:
	valgrind --leak-check=full ./exercise.out

clean:
	rm -f *.out
