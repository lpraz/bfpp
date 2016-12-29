/*
 * parse.h
 * Defines abstract functions for transpiling bfpp to Brainfuck.
 */

#ifndef PARSE_H
#define PARSE_H

/* Local includes */
#include "vector.h"

/* Stdlib includes */
#include <stdio.h>

/* Symbolic constants */
#define MACRO_OPEN_CHAR '('
#define MACRO_CLOSE_CHAR ')'
#define FUNC_OPEN_CHAR '{'
#define FUNC_CLOSE_CHAR '}'
#define COMMENT_OPEN_CHAR '~'
#define COMMENT_CLOSE_CHAR '~'

/* Transpiles a macro to its Brainfuck equivalent. */
void parse_macro(FILE *in, FILE *out);

/* Transpiles a function to its Brainfuck equivalent. */
void parse_func(FILE *in, FILE *out, Vector *funcs);

/* Transpiles a comment to its Brainfuck equivalent (removes it). */
void parse_comment(FILE *in);

#endif
