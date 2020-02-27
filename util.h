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
 * The number of results depend on the previous call of setSampleSize().
 */
void processData( double *points, size_t samples );

#endif