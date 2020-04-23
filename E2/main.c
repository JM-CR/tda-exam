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
    uint8_t message = 0x1A;
    size_t bits = 6;

    // Encode
    uint16_t encoding = encode(message, bits);
    printf("Mensaje codificado: 0x%X\n", encoding);

    // Change bit
    changeBit(&encoding, 2);
    printf("Mensaje transmitido: 0x%X\n\n", encoding);

    // Check error
    unsigned int error = checkError(encoding, bits);
    printf("Posición del error: %u\n", error - 1);
    if ( error != 0 ) {
        changeBit(&encoding, error - 1);
    }

    // Decode
    uint8_t decoding = decode(encoding, bits);
    printf("Mensaje decodificado: 0x%X\n", decoding);

    return 0;
}
