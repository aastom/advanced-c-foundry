#include <stdio.h>
#include <stdlib.h>
#include "../../common/utils.h"

// TODO: Include your arena allocator header here
// #include "my_arena.h"

#define NUM_ALLOCS 100000
#define OBJ_SIZE 32

// A sample object to allocate
typedef struct {
    int id;
    char data[OBJ_SIZE - sizeof(int)];
} MyObject;

void run_with_malloc() {
    MyObject *objs[NUM_ALLOCS];

    for (int i = 0; i < NUM_ALLOCS; i++) {
        objs[i] = (MyObject *)malloc(sizeof(MyObject));
        if (objs[i] == NULL) {
            log_err("malloc failed");
            return;
        }
        objs[i]->id = i;
    }

    for (int i = 0; i < NUM_ALLOCS; i++) {
        free(objs[i]);
    }
}

void run_with_arena() {
    // TODO: Create an arena. It should be large enough to hold all objects.
    // size_t arena_size = NUM_ALLOCS * sizeof(MyObject) + 1024; // Extra space
    // MyArena arena = arena_create(arena_size);

    // TODO: Allocate objects from the arena in a loop.
    // for (int i = 0; i < NUM_ALLOCS; i++) {
    //     MyObject* obj = (MyObject*)arena_alloc(&arena, sizeof(MyObject));
    //     obj->id = i;
    // }

    // TODO: Free the entire arena at the end.
    // arena_free(&arena);
}

int main() {
    Timer t;

    log_info("Running with repeated malloc/free...");
    timer_start(&t);
    run_with_malloc();
    double malloc_time = timer_stop(&t);
    printf("Time with malloc: %.2f ms\n", malloc_time);

    log_info("Running with arena allocator (TODO)...");
    timer_start(&t);
    run_with_arena();
    double arena_time = timer_stop(&t);
    printf("Time with arena: %.2f ms\n", arena_time);

    printf("\n--- Exercise Goal ---\n");
    printf("1. Implement your own arena allocator (my_arena.h, my_arena.c).\n");
    printf("2. Complete the run_with_arena() function.\n");
    printf("3. Compare the execution times.\n");
    printf("4. Run 'valgrind --leak-check=full' on the compiled program to ensure no leaks.\n");

    return 0;
}
