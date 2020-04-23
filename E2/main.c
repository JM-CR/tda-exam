// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 23/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "hamming.h"

#define DATA_SIZE 4
#define FULL_SIZE 7

int main( int argc, char *argv[] ) {
    // Create message
    uint8_t message = 0x9;
    printf("Dato: %s\n", numberToBinary(message, DATA_SIZE));

    // Encode
    uint16_t encoding = encode(message, DATA_SIZE);
    printf("Mensaje codificado: %s\n\n", numberToBinary(encoding, FULL_SIZE));

    // Change bit
    changeBit(&encoding, 2);
    printf("Mensaje transmitido: %s\n", numberToBinary(encoding, FULL_SIZE));

    // Check error
    unsigned int error = checkError(encoding, FULL_SIZE);
    printf("Posición del error: %u\n\n", error);
    if ( error != 0 ) {
        changeBit(&encoding, error - 1);
    }

    // Decode
    uint8_t decoding = decode(encoding, DATA_SIZE);
    printf("Mensaje decodificado: %s\n", numberToBinary(decoding, DATA_SIZE));

    return 0;
}
