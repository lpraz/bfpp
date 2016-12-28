/*
 * func.h
 * Defines structure of, and abstract functions for dealing with, bfpp
 * functions.
 */

#ifndef FUNC_H
#define FUNC_H

/* Structure */
typedef struct Function {
    char *name;
    char *code;
} Function;

/* Initializes a function. */
Function func_init(char *name, char *code);

/* Searches for a function with the specified name in an array of
 * functions and returns its code, if it exists.
 */
char *func_find(char *name);

#endif
