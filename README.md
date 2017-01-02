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
More complex statements can be defined as functions and re-used at any
point after their definition:

    {def shift_one_right}{[>+<-]>}
    {shift_one_right}{shift_one_right}

Function definitions cannot be nested within other function definitions.

### Comments (TODO)
Comments that could ordinarily not be written in Brainfuck due to
containing command characters can be written with surrounding tildes.

    ~TODO: Something useful.~
    ++++++++    ~Add 8 to current cell.~

## Building and (Un)Installing
 * Building: On Linux systems, just `git clone` this repository, then
    `make`.
 * Installing: After building, (`sudo`) `make install`. Your binary will be
    installed to `/usr/bin/bfpp` by default. If you don't like this, just
    change the `PREFIX` and `INSTTARGET` variables in the makefile.
 * Uninstalling: Just (`sudo`) `make uninstall`.
