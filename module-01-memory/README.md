# Module 01: Advanced Memory Management

This module moves beyond basic `malloc`/`free` to custom memory allocation strategies. The goal is to understand and implement allocators that can improve performance and reduce memory fragmentation for specific use cases.

## Pre-flight Check

Before starting, ensure you are comfortable with the concepts from Module 00. Specifically, you should be able to complete the exercises involving `void*` and pointer arithmetic, as these are fundamental to building a custom allocator.

## Concepts

1.  **Memory Debugging with `Valgrind`**: `Valgrind` is an essential tool for any C programmer. It can detect a wide range of memory errors, including:
    *   Invalid reads/writes (accessing memory you shouldn't).
    *   Use of uninitialized values.
    *   Memory leaks (forgetting to `free` memory).
    *   **Rule:** Any code you write for memory management *must* run clean under `valgrind --leak-check=full`.

2.  **Custom Allocators (Arena/Region)**: A standard `malloc` can be slow due to the overhead of finding a free block and managing the heap. An **arena allocator** is a simple yet powerful alternative. You pre-allocate a large, contiguous block of memory (the "arena") and then service allocation requests by simply bumping a pointer through this block. 

    *   **Advantage:** Allocations are extremely fast (just pointer arithmetic).
    *   **Advantage:** Deallocation of all objects at once is trivial (just reset the pointer).
    *   **Disadvantage:** You cannot free individual objects. The entire arena must be freed at once.

## Example & Exercise

*   `example_arena.c`: A clean, well-commented implementation of an arena allocator. Study this to understand the core logic.
*   `exercise.c`: A simple program that allocates many small objects. Your task is to modify it to use an arena allocator, based on the example, and verify the performance difference and `Valgrind` cleanliness.
