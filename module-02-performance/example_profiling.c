/*
 * example_profiling.c
 * 
 * This program has an intentionally inefficient function. The goal is to use
 * a profiler like gprof to identify the bottleneck.
 * 
 * To compile and run with gprof:
 * 1. gcc -Wall -pg -o example_profiling.out example_profiling.c
 * 2. ./example_profiling.out
 * 3. gprof ./example_profiling.out gmon.out > analysis.txt
 * 4. open analysis.txt and find the culprit!
 */
#include <stdio.h>

// An intentionally slow function
void hot_function() {
    double result = 0.0;
    // This loop is the bottleneck
    for (int i = 0; i < 100000000; i++) {
        result += (double)i / 3.14159;
    }
}

// A function that does less work
void cool_function() {
    int result = 0;
    for (int i = 0; i < 1000000; i++) {
        result += i;
    }
}

int main() {
    printf("Running program to find bottleneck...\n");

    hot_function();
    cool_function();

    printf("Program finished. Run gprof to see the analysis.\n");
    return 0;
}
