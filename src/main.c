/*
 * main.c
 * Provides top-level functions for bfpp.
 */

/* Local includes */
#include "args.h"

/* Stdlib includes */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    /* Declarations */
    FILE *in, *out;
    char *inpath, *outpath;
    char curchar;
    
    /* Read arguments, quit if necessary */
    if (args(argc, argv, inpath, outpath))
        return EXIT_SUCCESS;
    
    /* Open files */
    in = fopen(inpath, "r");
    out = fopen(inpath, "w");
    
    if (in == NULL || out == NULL) {
        printf("Error opening files");
        return EXIT_FAILURE;
    }
    
    /* Read in into out */
    /* TODO: process */
    while (curchar = fgetc(in), curchar != EOF)
        fputc(curchar, out);
    
    /* Close files */
    fclose(in);
    fclose(out);
}
