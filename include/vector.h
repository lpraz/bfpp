/*
 * vector.h
 * Defines abstract functions for a vector (array list) of bfpp functions.
 * Only those functions of a vector needed by bfpp will be defined.
 */

#ifndef VECTOR_H
#define VECTOR_H

/* Local includes */
#include "func.h"

/* Structure */
typedef struct Vector {
    Function *arr
    int size;
    int cap;
} Vector;

/* Symbolic constants */
#define VECTOR_DEFAULT_SIZE 2

/* Initializes a vector. */
Vector vector_init(int cap);

/* Puts a function at the end of a vector. */
void vector_add(Vector *vec, Function func);

/* Searches a vector for a function and returns its code, if it exists. */
char *vector_find(Vector *vec, char *name);

/* Expands a vector. */
void vector_expand(Vector *vec);

/* Frees the memory used for a vector. */
void vector_free(Vector *vec);

#endif
