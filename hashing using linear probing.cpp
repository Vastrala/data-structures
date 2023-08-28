#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Hash table structure
struct HashTable {
    int keys[SIZE];
    int values[SIZE];
};

// Initialize the hash table
void initHashTable(struct HashTable *table) {
    for (int i = 0; i < SIZE; i++) {
        table->keys[i] = -1; // -1 indicates an empty slot
        table->values[i] = -1;
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert a key-value pair into the hash table
void insert(struct HashTable *table, int key, int value) {
    int index = hash(key);
    
    // Linear probing to find an empty slot
    while (table->keys[index] != -1) {
        index = (index + 1) % SIZE;
    }
    
    table->keys[index] = key;
    table->values[index] = value;
}

// Search for a key in the hash table
int search(struct HashTable *table, int key) {
    int index = hash(key);
    
    // Linear probing to find the key
    while (table->keys[index] != -1) {
        if (table->keys[index] == key) {
            return table->values[index];
        }
        index = (index + 1) % SIZE;
    }
    
    return -1; // Key not found
}

int main() {
    struct HashTable table;
    initHashTable(&table);
    
    insert(&table, 5, 25);
    insert(&table, 15, 75);
    insert(&table, 25, 125);
    
    int key_to_search = 15;
    int value_found = search(&table, key_to_search);
    
    if (value_found != -1) {
        printf("Value for key %d: %d\n", key_to_search, value_found);
    } else {
        printf("Key %d not found.\n", key_to_search);
    }
    
    return 0;
}