// See hamming.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: hamming.c
// Date: 23/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "hamming.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private global variables */

static unsigned int r_positions[] = { 0, 1, 3, 7, 15 };  

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
static bool isParityPosition( unsigned int pos ) {
    bool flag = false;
    size_t size = sizeof(r_positions) / sizeof(int);
    for ( size_t n = 0; n < size; ++n ) {
        if ( r_positions[n] == pos ) {
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
static uint16_t createContainer( uint8_t from, size_t size ) {
    uint16_t bit, result = 0x0000;
    for ( size_t n = 0, pos = 0; n < size; n++, pos++ ) {
        bit = getBit(from, n);
        while ( isParityPosition(pos) ) pos++;
        insertBit(bit, &result, pos);
    }
    return result;
}

/**
 * Calculates and adds the redundancy bits.
 *
 * @param holder Holder with the data bits.
 * @param size Number of bits in the message.
 */
static void addParityBits( uint16_t *holder, size_t size ) {
    // Calculate number of bits
    unsigned int total = 0;
    while ( pow(2, total) < (size + total + 1) ) {
        total++;
    }

    // Calculate values
    uint16_t parity, pos;
    for ( int r = 0, cycles; r < total; ++r ) {
        // Get first bit
        if ( r == 0 || r == 1 ) {
            pos = 2;
            parity = getBit(*holder, pos);
            cycles = 0;
        } else {
            pos = pow(2, r);
            parity = getBit(*holder, pos);
            cycles = r;
        }

        // XOR
        bool flag = true;
        while ( flag ) {
            // Position to read
            if ( cycles == 0 ) {
                pos += pow(2, r) + 1;
                cycles = r;
            } else {
                pos++;
                cycles--;
            }

            // Logical operation
            if ( pos < size + total ) {
                parity ^= getBit(*holder, pos);
            } else {
                flag = false;
            }
        }

        // Add result
        insertBit(parity, holder, r_positions[r]);
    }
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

uint16_t encode( uint8_t message, size_t size ) {
    uint16_t result = createContainer(message, size);
    addParityBits(&result, size);
    return result;
}

void changeBit( uint16_t *encoding, unsigned int pos ) {
    *encoding ^= 0x0001 << pos;
}
