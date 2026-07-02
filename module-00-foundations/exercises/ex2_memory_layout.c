#include <stdio.h>

// A simple struct
struct Simple {
    char a;
    int b;
};

// A struct designed to show padding
struct Padded {
    char c;  // 1 byte
    // 3 bytes padding
    int i;   // 4 bytes
    char d;  // 1 byte
    // 7 bytes padding
    long l;  // 8 bytes
};

// Same members, different order
struct NotPadded {
    long l;  // 8 bytes
    int i;   // 4 bytes
    char c;  // 1 byte
    char d;  // 1 byte
    // 2 bytes padding
};


int main() {
    printf("--- Memory Layout Challenges ---\n\n");

    // --- Challenge 1: Size of Basic Types ---
    // TODO: Print the size of char, int, long, and float
    printf("Challenge 1:\n");
    printf("sizeof(char): %zu bytes\n", sizeof(char));
    printf("sizeof(int): %zu bytes\n", sizeof(int));
    printf("sizeof(long): %zu bytes\n", sizeof(long));
    printf("sizeof(float): %zu bytes\n\n", sizeof(float));

    // --- Challenge 2: Struct Padding ---
    // TODO: Print the size of the Simple, Padded, and NotPadded structs.
    //       Why are they different?
    printf("Challenge 2:\n");
    printf("sizeof(Simple): %zu bytes\n", sizeof(struct Simple));
    printf("sizeof(Padded): %zu bytes\n", sizeof(struct Padded));
    printf("sizeof(NotPadded): %zu bytes\n\n", sizeof(struct NotPadded));
    printf("Note: The size of Padded is larger due to memory alignment. Compilers add padding to align members on natural boundaries (e.g., an int on a 4-byte boundary), which can improve access speed on some architectures.\n");

    return 0;
}
