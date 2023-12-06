// cache.c
#include <string.h>
#include "cache.h"
#include <stdio.h>
#include <stdlib.h>

void moveNodeToFrontInCache(LRUCache* cache, Node* node) {
    // Remove the node from its current position
    if (node->back != NULL) {
        node->back->next = node->next;
    } else {
        cache->h = node->next;
    }

    if (node->next != NULL) {
        node->next->back = node->back;
    } else {
        cache->t = node->back;
    }

    // Move the node to the front
    node->next = cache->h;
    node->back = NULL;

    if (cache->h != NULL) {
        cache->h->back = node;
    }

    cache->h = node;

    // Update t if needed
    if (cache->t == NULL) {
        cache->t = cache->h;
    }
}
void insertNode(LRUCache* cache, int key) {
    // Check if the cache is full
    if (cache->capacity <= 0) {
        return; // Cache is disabled
    }

    // Check if the key already exists
    Node* current = cache->h;
    while (current != NULL) {
        if (current->key == key) {
            // Key already exists, update its position to the front
            moveToFront(cache, current);
            return;
        }
        current = current->next;
    }

      // Create a new node for the key
    Node* a = (Node*)malloc(sizeof(Node));
    a->key = key;
    a->next = NULL;
    a->back = NULL;

    // Insert the new node at the front
    if (cache->h == NULL) {
        // Cache is empty
        cache->h = a;
        cache->t = a;
    } else {
        a->next = cache->h;
        cache->h->back = a;
        cache->h = a;
    }

    // Check if the cache exceeds its capacity
    if (cache->capacity > 0 && cache->capacity < countNodes(cache)) {
        // Evict the least recently used node (from the t)
        Node* temp = cache->t;
        cache->t = cache->t->back;
        if (cache->t != NULL) {
            cache->t->next = NULL;
        }
        free(temp);
    }
}

// Function to access a key (marks it as recently used)
void accessKey(LRUCache* cache, int key) {
    Node* current = cache->h;
    while (current != NULL) {
        if (current->key == key) {
            // Key found, move it to the front
            moveToFront(cache, current);
            return;
        }
        current = current->next;
    }
}

int countNodes(LRUCache* cache) {
    int count = 0;
    for (Node* current = cache->h; current != NULL; current = current->next) {
        count++;
    }
    return count;
}
// Function to move a node to the front (most recently used)
void moveToFront(LRUCache* cache, Node* node) {
    // Implementation left as an exercise
}

// Utility function to print the cache content
void printCache(LRUCache* cache) {
    printf("Cache Content: ");
    for (Node* current = cache->h; current != NULL; current = current->next) {
        printf("%d ", current->key);
    }
    printf("\n");
}
// Function to initialize a new LRUCache
LRUCache* initCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->h = NULL;
    cache->t = NULL;
    return cache;
}

// Function to free the memory occupied by the cache
void destroyCache(LRUCache* cache) {
    for (Node* current = cache->h; current != NULL; ) {
        Node* p = current;
        current = current->next;
        free(p);
    }
    free(cache);
}


// Function to read video data from storage
char* readVideoData(const char* storagePath) {
    FILE* file = fopen(storagePath, "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        rewind(file);
        char* data = (char*)malloc(fileSize + 1);
        fread(data, sizeof(char), fileSize, file);
        data[fileSize] = '\0'; // Null-terminate the string
        fclose(file);
        return data;
    }
    return NULL;
}

// Other utility functions...
