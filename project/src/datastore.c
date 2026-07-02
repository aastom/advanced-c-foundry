#include "datastore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creates the datastore
Datastore* ds_create() {
    Datastore *ds = (Datastore*)malloc(sizeof(Datastore));
    if (ds) {
        ds->head = NULL;
    }
    return ds;
}

// Sets a key-value pair. Overwrites if key exists.
void ds_set(Datastore *ds, const char *key, const char *value) {
    DataNode *current = ds->head;
    // First, check if the key already exists
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            strncpy(current->value, value, VALUE_MAX_LEN - 1);
            return;
        }
        current = current->next;
    }

    // If key not found, create a new node
    DataNode *newNode = (DataNode*)malloc(sizeof(DataNode));
    if (!newNode) return; // Allocation failed

    strncpy(newNode->key, key, KEY_MAX_LEN - 1);
    strncpy(newNode->value, value, VALUE_MAX_LEN - 1);
    newNode->next = ds->head;
    ds->head = newNode;
}

// Gets a value by key
const char* ds_get(Datastore *ds, const char *key) {
    DataNode *current = ds->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return "(null)"; // Key not found
}

// Frees all memory used by the datastore
void ds_destroy(Datastore *ds) {
    DataNode *current = ds->head;
    DataNode *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(ds);
}
