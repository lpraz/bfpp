/*
 * main.c
 * Provides top-level functions for bfpp.
 */

/* Local includes */
#include "args.h"
#include "parse.h"
#include "vector.h"

/* Stdlib includes */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    /* Declarations - file I/O */
    FILE *in, *out;
    char *inpath, *outpath;
    int inchar;
    
    /* Declaraitons - funcs */
    Vector funcs = vector_init(VECTOR_DEFAULT_SIZE);
    
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
        if (inchar == MACRO_OPEN_CHAR)
            parse_macro(in, out);
        else if (inchar == FUNC_OPEN_CHAR)
            parse_func(in, out, &funcs);
        else if (inchar == COMMENT_OPEN_CHAR)
            parse_comment(in);
        else
            fputc(inchar, out);
        
        inchar = fgetc(in);
    }
    
    /* Close files */
    fclose(in);
    fclose(out);
}
