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
    /* Declarations - file I/O */
    FILE *in, *out;
    char *inpath, *outpath;
    int inchar;
    
    /* Declarations - parsing macros */
    char *mult_str;
    int mult_strlen;
    char cmd;
    int mult;
    
    /* Read arguments, quit if necessary */
    if (args(argc, argv, inpath, outpath))
        return EXIT_SUCCESS;
    
    /* Open files */
    in = fopen("test/bf/in.bfpp", "r");
    out = fopen("test/bf/out.bf", "w");
    
    if (in == NULL || out == NULL) {
        printf("Error opening files\n");
        return EXIT_FAILURE;
    }
    
    /* Read in into out */
    inchar = fgetc(in);
    while (inchar != EOF) {
        if (inchar == '(') {
            cmd = fgetc(in);        /* Command */
            fseek(in, 1, SEEK_CUR); /* Comma */
            
            mult_strlen = 0;        /* Multiplier */
            mult_str = malloc(256 * sizeof(char));
            inchar = fgetc(in);
            
            while (inchar != ')') {
                mult_str[mult_strlen] = inchar;
                mult_strlen++;
                inchar = fgetc(in);
            }
            
            mult_str[mult_strlen] == '\0';
            mult = atoi(mult_str);
            
            for (int i = 0; i < mult; i++)
                fputc(cmd, out);
            
        } else {
            fputc(inchar, out);
        }
        inchar = fgetc(in);
    }
    
    /* Close files */
    fclose(in);
    fclose(out);
}
