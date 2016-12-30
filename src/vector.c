/*
 * vector.c
 * Provides functions for a vector (array list) of bfpp functions.
 */

/* Include self */
#include "vector.h"

/* Local includes */
#include "func.h"

/* Stdlib includes */
#include <stdlib.h>
#include <string.h>

/* Initializes a vector. */
Vector vector_init(int cap) {
    Function *arr = malloc(cap * sizeof(Function));
    Vector vec = {arr, 0, cap};
    return vec;
}

/* Puts a function at the end of a vector. */
void vector_add(Vector *vec, Function func) {
    if ((*vec).size == (*vec).cap)
        vector_expand(vec);
    
    (*vec).arr[(*vec).size++] = func;
}

/* Searches a vector for a function and returns its code, if it exists. */
char *vector_find(Vector *vec, char *name) {
    for (int i = 0; i < (*vec).size; i++)
        if (strcmp((*vec).arr[i].name, name) == 0)
            return (*vec).arr[i].code;
    
    return NULL;
}

/* Expands a vector. */
void vector_expand(Vector *vec) {
    (*vec).cap *= 2;
    (*vec).arr = realloc((*vec).arr, (*vec).cap * sizeof(Function));
}

/* Frees the memory used for a vector. */
void vector_free(Vector *vec) {
    free((*vec).arr);
}
