# Makefile for the Iterative Project

CC = gcc
# Enforce strict C standards and warnings
CFLAGS = -std=c11 -Wall -Wextra -Werror -I./src

# The name of the final executable
TARGET = app

# All source files
SOURCES = $(wildcard src/*.c)

# The object files generated from the source files
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean run

all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compile source files into object files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the application
run:
	./$(TARGET)

# Clean up build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)
