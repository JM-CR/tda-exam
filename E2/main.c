// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 23/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "hamming.h"

int main( int argc, char *argv[] ) {
    printf("0x%X\n", encode(0xA, 4));
    return 0;
}
