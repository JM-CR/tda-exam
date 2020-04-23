// This library simulates the hamming codes.
// Author: Josue Mosiah Contreras Rocha
// File: hamming.h
// Date: 23/04/20

#ifndef HAMMING_H
#define HAMMING_H

// -----------------------------
// System headers
// -----------------------------
#include <stdint.h>
#include <stddef.h>


// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * Encodes a message with the hamming redundance.
 *
 * @param message Message to encode.
 * @param size Number of bits in the message.
 * @return The encoded data.
 */
uint16_t encode( uint8_t message, size_t size );

/**
 * Simulates an error when transmiting the message.
 *
 * @param enconding Encoded message.
 * @param pos Position of the bit to change.
 */
void changeBit( uint16_t *encoding, unsigned int pos );

/**
 * Checks if an error occurred after transmission.
 *
 * @param encoding Encoded message.
 * @param size Number of bits in the original message.
 * @return Zero if no error; otherwise, the error's position.
 */
unsigned int checkError( uint16_t encoding, size_t size );

/**
 * Retrieves the data bits from a transmitted message.
 *
 * @param encoding Encoded message.
 * @param size Number of bits in the original message.
 * @return Decoded message.
 */
uint8_t decode( uint16_t encoding, size_t size );

/**
 * Prints the binary equivalent of a number.
 *
 * @param x Decimal number.
 * @param size Number of bits to print.
 * @return String with the result.
 */
const char *numberToBinary( int x, size_t size );

#endif
