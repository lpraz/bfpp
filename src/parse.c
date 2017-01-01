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

/* Transpiles a macro to its Brainfuck equivalent, writes to file. */
void parse_macro(FILE *in, FILE *out) {
    /* Declarations */
    char *mult_str = malloc(256 * sizeof(char));
    int mult_str_len = 0;
    char cmd;
    int mult;
    int temp_char;
    
    /* Input: command */
    cmd = fgetc(in);
    
    /* Input: separator */
    fseek(in, 1, SEEK_CUR);
    
    /* Input: multiplier */
    temp_char = fgetc(in);
    while (temp_char != MACRO_CLOSE_CHAR) {
        mult_str[mult_str_len++] = temp_char;
        temp_char = fgetc(in);
    }
    
    /* End string, convert to int */
    mult_str[mult_str_len] == '\0';
    mult = atoi(mult_str);
    
    /* Output */
    for (int i = 0; i < mult; i++)
        fputc(cmd, out);
    
    free(mult_str);
}

/* Transpiles a macro to its Brainfuck equivalent, writes to str and
 * keeps track of its length.
 */
void parse_macro_str(FILE *in, char *out_str, int *out_str_len) {
    /* Declarations */
    char *mult_str = malloc(256 * sizeof(char));
    int mult_str_len = 0;
    char cmd;
    int mult;
    int temp_char;
    
    /* Input: command */
    cmd = fgetc(in);
    
    /* Input: separator */
    fseek(in, 1, SEEK_CUR);
    
    /* Input: multiplier */
    temp_char = fgetc(in);
    while (temp_char != MACRO_CLOSE_CHAR) {
        mult_str[mult_str_len++] = temp_char;
        temp_char = fgetc(in);
    }
    
    /* End string, convert to int */
    mult_str[mult_str_len] == '\0';
    mult = atoi(mult_str);
    
    /* Output */
    for (int i = 0; i < mult; i++)
        out_str[(*out_str_len)++] = cmd;
    
    free(mult_str);
}

/* Transpiles a function to its Brainfuck equivalent. */
void parse_func(FILE *in, FILE *out, Vector *funcs) {
    /* Declarations - func name */
    char *func_name = malloc(256 * sizeof(char));
    int func_name_len = 0;
    
    /* Declarations - func code */
    char *func_code;
    int func_code_len = 0;
    
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
    if (temp_char == ' ' && strcmp(func_name, "def") == 0) {
        /* Wipe func_name */
        memset(func_name, '\0', 4);
        func_name_len = 0;
        
        /* Func name */
        temp_char = fgetc(in);
        while (temp_char != FUNC_CLOSE_CHAR) {
            func_name[func_name_len++] = temp_char;
            temp_char = fgetc(in);
        }
        
        func_name[func_name_len] = '\0';
        
        /* Is this the right opening char? */
        temp_char = fgetc(in);
        if (temp_char != FUNC_OPEN_CHAR) {
            printf("Function %s has malformed definition!\n", func_name);
            return;
        }
        
        /* Func code */
        func_code = malloc(65536 * sizeof(char));
        temp_char = fgetc(in);
        while (temp_char != FUNC_CLOSE_CHAR) {
            if (temp_char == MACRO_OPEN_CHAR) {
                parse_macro_str(in, func_code, &func_code_len);
            } else if (temp_char == COMMENT_OPEN_CHAR) {
                parse_comment(in);
            } else {
                func_code[func_code_len++] = temp_char;
            }
            temp_char = fgetc(in);
        } 
        
        func_code[func_code_len] = '\0';
        
        /* Finish up, copy to list of funcs */
        func_code[func_code_len] = '\0';
        new_func = func_init(func_name, func_code);
        vector_add(funcs, new_func);
    } else {
        /* Search for a function with the name */
        func_code = vector_find(funcs, func_name);
        if (func_code == NULL)
            printf("Function %s undefined!\n", func_name);
        else
            fputs(func_code, out);
    }
    
    /* Don't free at the end, pointers are used in func list */
}

/* Transpiles a comment to its Brainfuck equivalent (discards it). */
void parse_comment(FILE *in) {
    fgetc(in);
    while (fgetc(in) != COMMENT_CLOSE_CHAR);
}
