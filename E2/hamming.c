// See hamming.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: hamming.c
// Date: 23/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include "hamming.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private global variables */

static unsigned int redudancy[] = { 0, 1, 3, 7, 15 }; 

/* Private functions */

/** 
 * Gets a bit from the specific position.
 *
 * @param from Number to process.
 * @param at Bit position to retrieve (Starting with 0).
 * @return The requested value.
 */
static uint16_t getBit( uint16_t from, unsigned int at ) {
    uint16_t mask = 0x0001 << at;
    uint16_t temp = from & mask;
    return temp >> at;
}

/**
 * Inserts a bit at a given position.
 *
 * @param bit Bit to insert.
 * @param at Variable where the bit will be inserted.
 * @param pos Position to insert at the variable (Starting with 0).
 */
static void insertBit( uint8_t bit, uint16_t *at, unsigned int pos ) {
    uint16_t value = bit << pos;
    *at |= value;
}

/**
 * Checks if a position is for a redundancy bit.
 *
 * @param pos Position to check (Starting from 0).
 * @return True for redundancy position; otherwise, false
 */
static bool isRedundacyPosition( unsigned int pos ) {
    bool flag = false;
    size_t size = sizeof(redudancy) / sizeof(int);
    for ( size_t n = 0; n < size; ++n ) {
        if ( redudancy[n] == pos ) {
            flag = true;
            break;
        }
    }
    return flag;
}

/**
 * Creates a holder for the encoded message with the data bits inserted.
 *
 * @param from Message to insert.
 * @param size Number of bits in the message.
 * @return Holder with the initial values.
 */
static uint16_t createHolder( uint8_t from, size_t size ) {
    uint16_t bit, result = 0x0000;
    for ( size_t n = 0, pos = 0; n < size; n++, pos++ ) {
        bit = getBit(from, n);
        while ( isRedundacyPosition(pos) ) pos++;
        insertBit(bit, &result, pos);
    }
    return result;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

uint16_t encode( uint8_t message, size_t size ) {
    uint16_t result = createHolder(message, size);

    return result;
}
