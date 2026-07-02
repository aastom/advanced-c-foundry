#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A macro for logging with file and line number
#define log_info(M, ...) fprintf(stdout, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// A simple structure for timing code blocks
 typedef struct {
    struct timespec start;
    struct timespec end;
} Timer;

// Start the timer
void timer_start(Timer *t);

// Stop the timer and return elapsed milliseconds
double timer_stop(Timer *t);

#endif // COMMON_UTILS_H
