# Makefile for Module 02

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean profile

all: example_profiling.out

# Standard build
example_profiling.out: example_profiling.c
	$(CC) $(CFLAGS) -o $@ $^

# Build for profiling with gprof
profile: example_profiling.c
	$(CC) $(CFLAGS) -pg -o example_profiling_prof.out $^
	@echo "\nTo generate profile:"
	@echo "1. ./example_profiling_prof.out"
	@echo "2. gprof ./example_profiling_prof.out gmon.out > analysis.txt"

clean:
	rm -f *.out *.out.prof gmon.out analysis.txt
