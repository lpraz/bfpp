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

#endif
