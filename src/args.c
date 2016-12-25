/*
 * args.c
 * Provides functions for processing command-line arguments.
 */

/* Include self */
#include "args.h"

/* Stdlib includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Processes command-line arguments. */
bool args(int argc, char **argv, char *in, char *out) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {
            printf("bfpp: the Brainfuck preprocessor\n");
            return true;
        } else if (strcmp(argv[i], "--help") == 0) {
            printf("Usage: bfpp [INFILE] [OUTFILE]\n");
            return true;
        }
    }
    
    in = malloc(strlen(argv[1]) * sizeof(char));
    strcpy(argv[1], in);
    
    out = malloc(strlen(argv[2]) * sizeof(char));
    strcpy(argv[2], out);
    
    return false;
}
