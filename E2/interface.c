// See interface.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: interface.c
// Date: 23/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include "interface.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private functions */

/**
 * Reads an integer from the console and saves the result.
 *
 * @param state Location for the result.
 * @param lower Minimum value.
 * @param upper Maximum value.
 */
static void readOption( int *state, int lower, int upper ) {
    // Read
    int option = INT_MAX;
    printf("-> ");
    do {
        scanf("%d", &option);
        setbuf(stdin, NULL);
    } while ( option < lower || option > upper );

    // Save
    *state = option;
}

/**
 * Prints the binary equivalent of a number.
 *
 * @param x Decimal number.
 * @param size Number of bits to print.
 * @return String with the result.
 */
static const char *numberToBinary( int x, size_t size ) {
    // Convert
    static char b[10];
    b[0] = '\0';
    for ( uint16_t z = pow(2, size - 1); z > 0; z >>= 1 ) {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }
    return b;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void initialGuide( void ) {
    printf(
        "\nCorrecto uso del programa:\n"
        "\t1. Ingresar dato a transmitir.\n"
        "\t2. Indicar posición del bit de error.\n"
        "\t3. Esperar a que se muestre en pantalla los resultados.\n\n"
        "Consideraciones:\n"
        "\t1. El dato de entrada debe estar entre 0 y 15.\n"
        "\t2. La posición del error debe estar entre 1 y 7.\n"
    );
}

unsigned int askValue( char *text, int lower, int upper ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "%s", text
    );
    int option;
    readOption(&option, lower, upper);

    // Translate
    return option;
}

void printBinary( char *text, int number, size_t size ) {
    const char *binary = numberToBinary(number, size);
    printf("%s%s\n", text, binary);
}
