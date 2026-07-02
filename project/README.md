# The Iterative Project

This directory contains the source code for the project that will be evolved as you complete the modules. It starts as a very simple command-line tool and will become more robust and complex with each step.

## Project Evolution

The state of the project will be marked with Git tags after each module's concepts are applied.

*   **`v0.1-base` (Initial State):**
    *   A simple key-value store that reads commands from stdin.
    *   Uses standard `malloc` and `free` for memory management.
    *   Single-threaded.
    *   **Your Goal:** Get this version running and understand its simple structure.

*   **`v1.0-arena` (After Module 1):**
    *   **Goal:** Refactor the project to use the arena allocator you built for all its data storage needs. This will involve removing all `malloc` calls related to data items and replacing them with `arena_alloc`.

*   **`v2.0-optimized` (After Module 2):**
    *   **Goal:** Profile the application under a heavy load (e.g., adding many items) and identify any performance hotspots. Apply a simple, targeted optimization.

*   **`v3.0-threaded` (After Module 3):**
    *   **Goal:** Offload a task (e.g., writing data to a file, processing a complex value) to a worker thread. Use a mutex to protect access to the data store.
