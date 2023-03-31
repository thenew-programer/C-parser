#ifndef MAIN_H
#define MAIN_H

/* Macros*/
#define BUFFER 10 /* the size of the syntax (remember we are in C :(  )*/


/* Include all the libraries that I'm gonna need in this assembler */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


/* the states of FSM*/
typedef const enum
{
        S_I, S_F, S_M, S_STOP
}State;


/* Parser function and it's local functions also*/
bool parser(char *, int *);

bool isDigit(char );
#endif /* MAIN_H*/
