/*
 * parse.c
 * Provides functions for transpiling bfpp to Brainfuck.
 */

/* Include self */
#include "parse.h"

/* Local includes */
#include "vector.h"

/* Stdlib includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void parse_func(FILE *in, FILE *out, Vector *funcs) {
    /* Declarations - func name */
    char *func_name = malloc(256 * sizeof(char));
    int func_name_len;
    
    /* Declarations - func code */
    char *func_code;
    int func_code_len;
    
    /* Declarations - other */
    Function new_func;
    int temp_char = fgetc(in);
    
    /* Read in a string */
    while (temp_char != ' ' && temp_char != FUNC_CLOSE_CHAR) {
        func_name[func_name_len++] = temp_char;
        temp_char = fgetc(in);
    }
    
    func_name[func_name_len] = '\0';
    
    /* Is this a definition? */
    if (strcmp(func_name, "def") == 0) {
        char *func_name = malloc(65536 * sizeof(char));
        temp_char = fgetc(in);
        func_name_len = 0;
        
        /* Func name */
        while (temp_char != FUNC_CLOSE_CHAR) {
            func_name[func_name_len++] = temp_char;
            temp_char = fgetc(in);
        }
        
        /* Is this the right opening char? */
        temp_char = fgetc(in);
        if (temp_char != FUNC_OPEN_CHAR) {
            printf("Function %s has malformed definition!", func_name);
            return;
        }
        
        /* Func code */
        temp_char = fgetc(in);
        while (temp_char != FUNC_CLOSE_CHAR) {
            func_code[func_code_len++] = temp_char;
            temp_char = fgetc(in);
        } 
        
        /* Finish up, copy to list of funcs */
        func_code[func_code_len] = '\0';
        new_func = func_init(func_name, func_code);
        vector_add(funcs, new_func);
    } else {
        /* Search for a function with the name */
        func_code = vector_find(funcs, func_name);
        if (func_code == NULL)
            printf("Function %s undefined!", func_name);
        else
            fputs(func_code, out);
    }
    
    /* Free everything */
    free(func_name);
    free(func_code);
}

/* Transpiles a comment to its Brainfuck equivalent (removes it). */
void parse_comment(FILE *in) {
    int inchar = fgetc(in);
    
    while (inchar != COMMENT_CLOSE_CHAR)
        inchar = fgetc(in);
}
