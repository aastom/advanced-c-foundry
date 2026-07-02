# Module 03: Multi-threading and Concurrency

This module introduces concurrent programming using the POSIX Threads (`pthreads`) library. The focus is on safely creating threads and protecting shared data.

## Pre-flight Check

Review the function pointer exercise from Module 00. The pattern of passing a function to another function is exactly how `pthread_create` works. The thread starts execution in a function you provide.

## Concepts

1.  **Threading Basics (`pthreads`)**: Learn the basic lifecycle of a thread:
    *   `pthread_create()`: To start a new thread. It requires a pointer to a function where the thread will begin execution.
    *   `pthread_join()`: To wait for a thread to finish its execution.

2.  **Synchronization with Mutexes**: When multiple threads access and modify the same data, you can have a **race condition**. A mutex (Mutual Exclusion) is a lock that ensures only one thread can access a critical section of code at a time, preventing race conditions.

## Example & Exercise

*   `example_mutex.c`: Demonstrates a race condition where two threads increment a shared counter, leading to an incorrect final value. It then shows how to fix this by protecting the counter with a `pthread_mutex_t`.
*   **Exercise**: Apply this concept to the iterative project. Identify a piece of work that can be done in a separate thread and implement it, using a mutex to protect any data shared between the main thread and the worker thread.
