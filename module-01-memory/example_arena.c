#include "example_arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Align `s` up to the nearest multiple of `a`
#define ALIGN_UP(s, a) (((s) + (a) - 1) & ~((a) - 1))

// Default alignment for memory allocations
#define DEFAULT_ALIGNMENT (2 * sizeof(void*))

/**
 * @brief Creates a memory arena of a given size.
 * This function allocates a large block of memory from the heap that can be used
 * for many smaller, fast allocations.
 */
Arena arena_create(size_t size) {
    Arena arena;
    // Use calloc to get zero-initialized memory, which is a good practice.
    arena.base = (unsigned char *)calloc(size, 1);
    arena.size = size;
    arena.offset = 0;
    if (arena.base == NULL) {
        fprintf(stderr, "Failed to allocate memory for arena\n");
    }
    return arena;
}

/**
 * @brief Allocates a block of memory from the arena.
 * This is a "bump allocator": it simply moves a pointer forward.
 * This is much faster than malloc but doesn't allow for individual frees.
 */
void* arena_alloc(Arena *arena, size_t size) {
    // Align the allocation size to prevent alignment issues with subsequent allocations
    size_t aligned_size = ALIGN_UP(size, DEFAULT_ALIGNMENT);

    // Check if there's enough space left in the arena
    if (arena->offset + aligned_size > arena->size) {
        fprintf(stderr, "Arena out of memory!\n");
        return NULL;
    }

    // Get the pointer to the new block of memory
    void *ptr = arena->base + arena->offset;
    // Bump the offset for the next allocation
    arena->offset += aligned_size;

    // Zero the allocated memory
    memset(ptr, 0, aligned_size);

    return ptr;
}

/**
 * @brief Resets the arena's offset, effectively "freeing" all allocated memory at once.
 */
void arena_reset(Arena *arena) {
    arena->offset = 0;
    // Optionally, you could zero the entire arena memory here for security
    // memset(arena->base, 0, arena->size);
}

/**
 * @brief Releases the backing memory for the entire arena back to the system.
 */
void arena_free(Arena *arena) {
    free(arena->base);
    arena->base = NULL;
    arena->size = 0;
    arena->offset = 0;
}

// Main function to demonstrate the arena allocator
int main() {
    printf("--- Arena Allocator Example ---\n");

    // Create a 1MB arena
    Arena main_arena = arena_create(1024 * 1024);

    // Allocate some objects
    int *my_int = (int*)arena_alloc(&main_arena, sizeof(int));
    if (my_int) *my_int = 123;

    double *my_double = (double*)arena_alloc(&main_arena, sizeof(double));
    if (my_double) *my_double = 456.789;

    char *my_string = (char*)arena_alloc(&main_arena, 50);
    if (my_string) strcpy(my_string, "Hello, Arena!");

    printf("Int: %d\n", *my_int);
    printf("Double: %f\n", *my_double);
    printf("String: %s\n", my_string);
    printf("Arena offset after allocations: %zu bytes\n", main_arena.offset);

    // Reset the arena (all pointers are now invalid)
    arena_reset(&main_arena);
    printf("Arena offset after reset: %zu bytes\n", main_arena.offset);

    // The pointers my_int, my_double, my_string are now dangling. Accessing them is a bug!

    // Allocate again after reset
    int *another_int = (int*)arena_alloc(&main_arena, sizeof(int));
    if(another_int) *another_int = 999;

    printf("Another Int after reset: %d\n", *another_int);
    printf("Arena offset after second allocation: %zu bytes\n", main_arena.offset);

    // Free the entire arena at the end
    arena_free(&main_arena);
    printf("Arena freed.\n");

    return 0;
}
