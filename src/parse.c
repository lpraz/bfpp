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
    int mult_str_len = 0;
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
        mult_str[mult_str_len++] = mult_char;
        mult_char = fgetc(in);
    }
    
    mult_str[mult_str_len] == '\0';
    mult = atoi(mult_str);
    
    /* Output */
    for (int i = 0; i < mult; i++)
        fputc(cmd, out);
    
    free(mult_str);
}

/* Transpiles a function to its Brainfuck equivalent. */
/* TODO: implement this */
void parse_func(FILE *in, FILE *out) {
    char *func_name = malloc(256 * sizeof(char));
    int func_name_len;
    int func_char;
    
    func_char = fgetc(in);
    
    while (func_char != ' ' && func_char != FUNC_CLOSE_CHAR) {
        func_name[func_name_len++] = func_char;
        func_char = fgetc(in);
    }
    
    if (strcmp(func_char, "def") == 0) {
        func_char = fgetc(in);
        func_name_len = 0;
        
        while (func_char != FUNC_CLOSE_cHAR) {
            func_name[func_name_len++] = func_char;
            func_char = fgetc(in);
        }
    } else {
        
    }
    
    free(func_name);
}

/* Transpiles a comment to its Brainfuck equivalent (removes it). */
void parse_comment(FILE *in) {
    int inchar = fgetc(in);
    
    while (inchar != COMMENT_CLOSE_CHAR)
        inchar = fgetc(in);
}
