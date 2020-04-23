// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 23/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "hamming.h"

int main( int argc, char *argv[] ) {
    // Create message
    uint16_t message = 0xA;
    size_t bits = 4;

    // Encode
    uint16_t encoding = encode(message, bits);
    printf("0x%X\n", encoding);

    // Change bit
    changeBit(&encoding, 3);
    printf("0x%X\n", encoding);

    // Check error
    unsigned int error = checkError(encoding, bits);
    printf("%u\n", error);

    // Decode

    return 0;
}
