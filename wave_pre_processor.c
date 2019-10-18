
// Header
// -----------------------------------------------------------------------> 80
/**
 * Pre-process WAVE file.
 * 
 **/

// Includes
// -----------------------------------------------------------------------> 80
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "wave_pre_processor.h"

// Defines
// -----------------------------------------------------------------------> 80
#define TRUE 1
#define FALSE 0

// Globals
// -----------------------------------------------------------------------> 80
unsigned char buffer4[4]; // 4 byte buffer.
unsigned char buffer2[2]; // 2 byte buffer.

// char* secondsToTime(float seconds);

FILE *ptr;
char *filename;
struct HEADER header;

// Code
// -----------------------------------------------------------------------> 80
int main(int argc, char **argv) {
    // Allocate memory for filnename, 1024 bytes (1 KB).
    filename = (char*) malloc(sizeof(char) * 1024);
    if (filename == NULL) {
        printf("Error in malloc\n");
        exit(1);
    }

    // Get file path
    char cwd[1024]; // 1024 Bytes (string).
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        strcpy(filename, cwd);

        // Get filename from command line.
        if (argc < 2) {
            printf("No wave file specified\n");
            return 1;
        }

        strcat(filename, "/");
        strcat(filename, argv[1]);
        printf("%s\n", filename);
    }

    // Open file3.
    printf("Opening file\n");
    ptr = fopen(filename, "rb");
    if (ptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    exit(1);
}