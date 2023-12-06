# DBMS-FINAL-PROJECT
# Video Processing and Caching Project

This project demonstrates a simple video processing and caching system using C. It involves video transcoding, storage, and a Least Recently Used (LRU) cache for efficient retrieval.

## Project Structure

- `main.c`: The main program that initializes the LRUCache, transcodes a video, writes transcoded video data to storage, and uses cache functions.
- `video.c`: Contains the video-related functions, such as transcoding using FFmpeg.
- `cache.c`: Implements the LRU cache, including functions for cache management and data retrieval.

## Build and Run

To build the project, use the following command in the terminal:

```bash
gcc main.c cache.c video.c -o video_app

NOTE THAT OUTPUT.hevc is the output file. Do not include it while running
