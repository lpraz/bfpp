/*
 * parse.c
 * Provides functions for transpiling bfpp to Brainfuck.
 */

/* Include self */
#include "parse.h"

/* Stdlib includes */
#include <stdio.h>
#include <stdlib.h>

/* Transpiles a macro to its Brainfuck equivalent. */
void parse_macro(FILE *in, FILE *out) {
    /* Declarations */
    char *mult_str = malloc(256 * sizeof(char));
    int mult_strlen = 0;
    char cmd;
    int mult;
    int mult_char;
    
    /* Input: command */
    cmd = fgetc(in);
    
    /* Input: separator */
    fseek(in, 1, SEEK_CUR);
    
    /* Input: multiplier */
    mult_char = fgetc(in);
    while (mult_char != MACRO_CLOSE_CHAR) {
        mult_str[mult_strlen++] = mult_char;
        mult_char = fgetc(in);
    }
    
    mult_str[mult_strlen] == '\0';
    mult = atoi(mult_str);
    
    /* Output */
    for (int i = 0; i < mult; i++)
        fputc(cmd, out);
    
    free(mult_str);
}

/* Transpiles a function to its Brainfuck equivalent. */
/* TODO: implement this */
void parse_func(FILE *in, FILE *out) {
}

/* Transpiles a comment to its Brainfuck equivalent (removes it). */
void parse_comment(FILE *in) {
    int inchar = fgetc(in);
    
    while (inchar != COMMENT_CLOSE_CHAR)
        inchar = fgetc(in);
}
