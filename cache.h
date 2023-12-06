// cache.h
#ifndef CACHE_H
#define CACHE_H

// Structure for a cache node
typedef struct Node {
    int key;
    struct Node* next;
    struct Node* back;
} Node;

// Structure for the cache
typedef struct LRUCache {
    int capacity;
    Node* h;
    Node* t;
} LRUCache;

// Function prototypes
void moveToFront(LRUCache* cache, Node* node);
void insertNode(LRUCache* cache, int key);
void accessKey(LRUCache* cache, int key);
int countNodes(LRUCache* cache);

#endif // CACHE_H
