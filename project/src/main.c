#include <stdio.h>
#include <string.h>
#include "datastore.h"

// Simple command parser
void process_command(Datastore *ds, char *line) {
    char command[10];
    char key[KEY_MAX_LEN];
    char value[VALUE_MAX_LEN];

    // sscanf is unsafe, but simple for this example
    int items = sscanf(line, "%s %s %s", command, key, value);

    if (items < 1) return;

    if (strcmp(command, "set") == 0 && items == 3) {
        ds_set(ds, key, value);
        printf("OK\n");
    } else if (strcmp(command, "get") == 0 && items == 2) {
        const char* found_value = ds_get(ds, key);
        printf("%s\n", found_value);
    } else if (strcmp(command, "exit") == 0) {
        return;
    } else {
        printf("ERROR: Unknown command or wrong number of arguments.\n");
        printf("Usage: set <key> <value> | get <key> | exit\n");
    }
}

int main() {
    Datastore *ds = ds_create();
    char line[512];

    printf("--- Simple Key-Value Store (v0.1-base) ---\n");
    printf("Enter commands: set <k> <v>, get <k>, exit\n");

    while (fgets(line, sizeof(line), stdin)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "exit") == 0) {
            break;
        }
        process_command(ds, line);
    }

    ds_destroy(ds);
    printf("Exiting.\n");

    return 0;
}
