#ifndef DATASTORE_H
#define DATASTORE_H

#define KEY_MAX_LEN 64
#define VALUE_MAX_LEN 256

// A single key-value pair
typedef struct DataNode {
    char key[KEY_MAX_LEN];
    char value[VALUE_MAX_LEN];
    struct DataNode *next;
} DataNode;

// The main datastore structure (a linked list)
typedef struct {
    DataNode *head;
} Datastore;

Datastore* ds_create();
void ds_set(Datastore *ds, const char *key, const char *value);
const char* ds_get(Datastore *ds, const char *key);
void ds_destroy(Datastore *ds);

#endif // DATASTORE_H
