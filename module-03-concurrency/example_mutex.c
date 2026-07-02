/*
 * example_mutex.c
 *
 * This example demonstrates a classic race condition and how to solve it
 * with a mutex.
 * 
 * Two threads will attempt to increment a shared counter. Without a mutex,
 * the final result will be unpredictable and likely incorrect.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_INCREMENTS 1000000

// --- Global Shared State ---
typedef struct {
    long long counter;
    pthread_mutex_t mutex; // The mutex to protect the counter
} SharedState;

// The function each thread will run
void* thread_func(void *arg) {
    SharedState *state = (SharedState *)arg;

    for (int i = 0; i < NUM_INCREMENTS; i++) {
        // --- Critical Section Start ---
        pthread_mutex_lock(&state->mutex);

        state->counter++; // This is the operation we need to protect

        pthread_mutex_unlock(&state->mutex);
        // --- Critical Section End ---
    }
    return NULL;
}

void run_with_race_condition() {
    long long unsafe_counter = 0;
    // A fake state to show the problem without a mutex
    SharedState fake_state = {.counter = 0};

    // Anonymous thread function for the race condition
    void* unsafe_thread_func(void* arg) {
        for (int i = 0; i < NUM_INCREMENTS; i++) {
            // RACE CONDITION HERE!
            // Read, increment, and write are not atomic.
            // Thread 1 reads value -> context switch -> Thread 2 reads same value
            // -> both threads write back the same incremented value.
            ((SharedState*)arg)->counter++;
        }
        return NULL;
    }

    pthread_t t1, t2;
    pthread_create(&t1, NULL, unsafe_thread_func, &fake_state);
    pthread_create(&t2, NULL, unsafe_thread_func, &fake_state);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Without mutex (with race condition), counter = %lld\n", fake_state.counter);
}


int main() {
    printf("--- Mutex Example ---\n");
    run_with_race_condition();

    // --- Run with Mutex ---
    SharedState safe_state;
    safe_state.counter = 0;
    // Initialize the mutex
    if (pthread_mutex_init(&safe_state.mutex, NULL) != 0) {
        perror("mutex init failed");
        return 1;
    }

    pthread_t t1, t2;

    // Create two threads
    pthread_create(&t1, NULL, thread_func, &safe_state);
    pthread_create(&t2, NULL, thread_func, &safe_state);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("With mutex, counter = %lld (Expected: %d)\n", safe_state.counter, NUM_INCREMENTS * 2);

    // Destroy the mutex
    pthread_mutex_destroy(&safe_state.mutex);

    return 0;
}
