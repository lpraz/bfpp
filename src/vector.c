/*
 * vector.c
 * Provides functions for a vector (array list) of bfpp functions.
 */

/* Include self */
#include "vector.h"

/* Initializes a vector. */
Vector vector_init(int cap) {
    Function *arr = malloc(cap * sizeof(Function));
    Vector vec= {arr, 0, cap};
}

/* Puts a function at the end of a vector. */
void vector_add(Vector *vec, Function func) {
    if ((*vec).size == (*vec).cap)
        vector_expand(vec);
    
    (*vec).arr[(*vec).size++] == func;
}

/* Searches a vector for a function and returns its code, if it exists. */
char *vector_find(Vector *vec, char *name) {
    
}

/* Expands a vector. */
void vector_expand(Vector *vec) {
    
}

/* Frees the memory used for a vector. */
void vector_free(Vector *vec) {
    
}
