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

/* Constants */

/* Types declarations */

/* Global variables */

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

#endif
