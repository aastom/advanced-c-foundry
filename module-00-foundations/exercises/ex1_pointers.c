#include <stdio.h>
#include <string.h>

// Function pointer type that takes two ints and returns an int
typedef int (*arithmetic_op)(int, int);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

// Higher-order function that takes a function pointer
void perform_op(int a, int b, arithmetic_op op) {
    int result = op(a, b);
    printf("Result: %d\n", result);
}

int main() {
    // --- Challenge 1: Pointer Arithmetic ---
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr points to arr[0]

    // TODO: Use pointer arithmetic to print the value '30'
    printf("Challenge 1: Value at ptr + 2 is %d\n", *(ptr + 2));

    // --- Challenge 2: Generic Pointers (void*) ---
    void *generic_ptr;
    int i = 123;
    float f = 45.6f;
    
    generic_ptr = &i;
    // TODO: Cast generic_ptr back to an int pointer and print the value.
    printf("Challenge 2 (int): %d\n", *(int*)generic_ptr);

    generic_ptr = &f;
    // TODO: Cast generic_ptr back to a float pointer and print the value.
    printf("Challenge 2 (float): %.1f\n", *(float*)generic_ptr);

    // --- Challenge 3: Function Pointers ---
    arithmetic_op operation;

    // TODO: Assign the 'add' function to the 'operation' pointer and call perform_op
    printf("Challenge 3 (add):\n");
    operation = add;
    perform_op(10, 5, operation);
    
    // TODO: Assign the 'subtract' function and call perform_op
    printf("Challenge 3 (subtract):\n");
    operation = subtract;
    perform_op(10, 5, operation);

    return 0;
}
