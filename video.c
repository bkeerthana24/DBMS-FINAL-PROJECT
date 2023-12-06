// video.c
#include <stdlib.h>
#include "video.h"
#include <stdio.h>
#include <string.h>

// Function to write video data to storage
void transcodeVideo(const char* inputFileName, const char* outputFileName) {

    // Form FFmpeg command line 
    char cmd[255];
    sprintf(cmd, "ffmpeg -i %s -c:v libx265 -crf 28 %s", inputFileName, outputFileName);
    
    // Execute FFmpeg command using system()
    if(system(cmd) != 0) {
        printf("Error transcoding video\n");
        exit(1); 
    }

    printf("Transcoding from %s to %s succeeded\n", inputFileName, outputFileName);

}
void writeVideoData(const char* data, const char* storagePath) {
    FILE* file = fopen(storagePath, "wb");
    if (file != NULL) {
        fwrite(data, sizeof(char), strlen(data), file);
        fclose(file);
    }
}
