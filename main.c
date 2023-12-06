#include "video.h"
#include "cache.h"
LRUCache* initCache(int capacity); 
// main.c
#include "video.h"

void transcodeVideo(const char* inputFileName, const char* outputFileName);
void moveNodeToFrontInCache(LRUCache* cache, Node* node);
LRUCache* initCache(int capacity);

int main() {
    // Initialize LRUCache with capacity 5
    LRUCache* cache = (LRUCache*) initCache(5);

    // Transcode video
    transcodeVideo("input.mp4", "output.hevc");

    // Write transcoded video data to storage
    char videoData[] = "Sample video data";
    writeVideoData(videoData, "video_storage.bin");

    // Insert node with key 1 to the cache
    insertNode(cache, 1);

    // Access key 1 in the cache
    accessKey(cache, 1);

    // Additional cache operations...
    Node* someNode = cache->h; // Assuming you have a node to perform operations on

    // Move someNode to the front (most recently used)
    moveNodeToFrontInCache(cache, someNode);

    // Evict some nodes based on cache eviction policy
    // EvictNodes(cache);

    return 0;
}
