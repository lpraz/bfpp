/*
 * args.h
 * Defines abstract functions for processing command-line arguments.
 */

#ifndef ARGS_H
#define ARGS_H

/* Stdlib includes */
#include <stdbool.h>

/* Processes command-line arguments. */
bool args(int argc, char **argv, char *in, char *out);

#endif
