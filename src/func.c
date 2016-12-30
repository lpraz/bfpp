/*
 * func.c
 * Provides functions for dealing with bfpp functions.
 */

/* Include self */
#include "func.h"

#include <stdio.h>
/* Initializes a function. */
Function func_init(char *name, char *code) {
    Function func = {name, code};
    return func;
}
