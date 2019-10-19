
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
#include "wave_preprocessor.h"

// Defines
// -----------------------------------------------------------------------> 80
#define TRUE 1
#define FALSE 0

// Globals
// -----------------------------------------------------------------------> 80
unsigned char buffer4[4]; // 4 byte buffer.
unsigned char buffer2[2]; // 2 byte buffer.

// char* secondsToTime(float seconds);

FILE *ptr;  // globally defining the FILE pointer to (FILE)ptr.
char *filename; // globally defining the pointer to (char)filename.
struct HEADER header; // globally defining the HEADER struct in our .h file.

// Code
// -----------------------------------------------------------------------> 80
// Main function is automatically run when called from the command line. The 
// 2 special arguments are (argc) the number of args, and (**argv) the double 
// pointer to the actual passed arguments.
int main(int argc, char **argv) {
    // Allocate memory for the filename buffer, 1024 bytes (1 KB).
    filename = (char*) malloc(sizeof(char) * 1024);
    if (filename == NULL) {
        printf("Error in malloc\n");
        exit(1);
    }

    // Get the current working directory(cwd) and store in a char[] buffer of 
    // size 1024 bytes. If the path exists (cwd ! NULL), then copy the cwd 
    // buffer into the filename buffer.
    char cwd[1024]; // 1024 Bytes (string).
    if (getcwd(cwd, sizeof(cwd)) != NULL) {

        // Copy instead of concat incase the buffer is not empty. If we were 
        // to concate the cwd into the filename buffer we cannot guarantee
        // the filename buffer is empty.
        strcpy(filename, cwd);

        // Get filename from the command line arguments. If there are less 
        // than 2 arguments, end the main function.
        if (argc < 2) {
            printf("No wave file specified\n");
            return 1;
        }

        // Add characters to the filename char buffer, including the
        // second commandline argument(filename of wave file).
        strcat(filename, "/");
        strcat(filename, argv[1]);
        printf("%s\n", filename);
    }

    // Open file as a readable binary(bytes) and store the FILE pointer in
    // (ptr).
    printf("Opening file\n");
    ptr = fopen(filename, "rb");
    if (ptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    exit(1);
}