// This library facilitates the use of the hamming codes.
// Author: Josue Mosiah Contreras Rocha
// File: interface.h
// Date: 23/04/20

#ifndef INTERFACE_H
#define INTERFACE_H

// -----------------------------
// System headers
// -----------------------------
#include <stddef.h>


// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * A little description about the program's behaviour.
 */
void initialGuide( void );

/**
 * Expects an input value from the user.
 *
 * @param text Instructions.
 * @param lower Minimum value.
 * @param upper Maximum value.
 * @return Given value by the user.
 */
unsigned int askValue( char *text, int lower, int upper );

/**
 * Prints the binary equivalent of a number.
 *
 * @param text Text to display.
 * @param number Number to print.
 * @param size Number of bits to print.
 */
void printBinary( char *text, int number, size_t size );

#endif
