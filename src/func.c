/*
 * func.c
 * Provides functions for dealing with bfpp functions.
 */

/* Include self */
#include "func.h"

/* Initializes a function. */
Function func_init(char *name, char *code) {
    Function func = {name, code};
    return func;
}

/* Searches for a function with the specified name in an array of
 * functions and returns its code, if it exists.
 */
/* TODO: Implement. May need to implement vector, too? */
char *func_find(char *name) {
    
}
