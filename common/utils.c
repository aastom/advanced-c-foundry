#include "utils.h"

/**
 * @brief Starts the timer.
 * Records the current high-resolution time.
 * @param t Pointer to the Timer struct.
 */
void timer_start(Timer *t) {
    if (t) {
        clock_gettime(CLOCK_MONOTONIC, &t->start);
    }
}

/**
 * @brief Stops the timer and calculates the elapsed time.
 * @param t Pointer to the Timer struct.
 * @return The elapsed time in milliseconds.
 */
double timer_stop(Timer *t) {
    if (t) {
        clock_gettime(CLOCK_MONOTONIC, &t->end);
        return ((t->end.tv_sec - t->start.tv_sec) * 1000.0) + 
               ((t->end.tv_nsec - t->start.tv_nsec) / 1000000.0);
    }
    return 0.0;
}
