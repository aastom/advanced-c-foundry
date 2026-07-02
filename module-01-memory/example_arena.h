#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

// The Arena structure: holds a large block of memory
typedef struct {
    unsigned char *base; // The beginning of the memory block
    size_t size;         // The total size of the block
    size_t offset;       // The current position within the block
} Arena;

/**
 * @brief Creates a new memory arena.
 * 
 * @param size The total size of the arena in bytes.
 * @return A new Arena struct, or an Arena with a NULL base on failure.
 */
Arena arena_create(size_t size);

/**
 * @brief Allocates memory from the arena.
 * 
 * This is a simple bump allocator. It does not support individual deallocations.
 * 
 * @param arena Pointer to the arena.
 * @param size The size of memory to allocate.
 * @return A pointer to the allocated memory, or NULL if the arena is full.
 */
void* arena_alloc(Arena *arena, size_t size);

/**
 * @brief Resets the arena, effectively deallocating all memory.
 * 
 * @param arena Pointer to the arena to reset.
 */
void arena_reset(Arena *arena);

/**
 * @brief Frees the entire arena's memory block.
 * 
 * @param arena Pointer to the arena to free.
 */
void arena_free(Arena *arena);

#endif // ARENA_H
