# Makefile for Module 03

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lpthread

.PHONY: all clean

all: example_mutex.out

example_mutex.out: example_mutex.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.out
