# bfpp (The **B**rain**fuck** **P**re-**P**rocessor)
Makes writing Brainfuck easier by translating its own custom 
Brainfuck-based syntax to pure Brainfuck.

## Example Syntax
bfpp is based on the contraction of Brainfuck into macros and functions.

### Macros
Repeated Brainfuck commands such as these:

    ++++++++

can be re-written as macros, which bfpp will translate back to the former:

    (+,8)

### Functions (TODO)
Will be implemented at a later date.

## Building and (Un)Installing
 * Building: On Linux systems, just `git clone` this repository, then
    `make`.
 * Installing: After building, (`sudo`) `make install`. Your binary will be
    installed to `/usr/bin/bfpp` by default. If you don't like this, just
    change the `PREFIX` and `INSTTARGET` variables in the makefile.
 * Uninstalling: Just (`sudo`) `make uninstall`.
