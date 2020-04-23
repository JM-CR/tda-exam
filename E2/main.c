// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 23/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "interface.h"
#include "hamming.h"

#define DATA_SIZE 4
#define FULL_SIZE 7

int main( int argc, char *argv[] ) {
    // Create message
    initialGuide();
    uint8_t message = askValue("Dato a transmitir ", 0, 15);
    printBinary("Mensaje: ", message, DATA_SIZE);

    // Encode
    uint16_t encoding = encode(message, DATA_SIZE);
    printBinary("Mensaje codificado: ", encoding, FULL_SIZE);

    // Change bit
    unsigned int position = askValue("Bit de error [7:1] ", 1, 7);
    changeBit(&encoding, position - 1);
    printBinary("\nMensaje transmitido: ", encoding, FULL_SIZE);

    // Check error
    unsigned int error = checkError(encoding, FULL_SIZE);
    printBinary("C[2:0]: ", error, 3);
    if ( error != 0 ) {
        changeBit(&encoding, error - 1);
    }

    // Decode
    uint8_t decoding = decode(encoding, DATA_SIZE);
    printBinary("\nMensaje decodificado: ", decoding, DATA_SIZE);
    printf("\n");

    return 0;
}
