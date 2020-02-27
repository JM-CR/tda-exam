// Utilities for the exam.
// Author: Josue Mosiah Contreras Rocha
// File: util.h
// Date: 17/02/20

#ifndef UTIL_H
#define UTIL_H

// -----------------------------
// System headers
// -----------------------------
#include "gnuplot.h"


// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * Sets the number of desired results for the Euler's method.
 * This function must be called before processData().
 *
 * @param size Number of results to process.
 */
void setSampleSize( unsigned int size );

/**
 * The number of results depend on the previous call of setSampleSize().
 */
void processData( double *points );

#endif