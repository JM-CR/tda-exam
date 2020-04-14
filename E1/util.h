// Some utility functions for the exam.
// Author: Josue Mosiah Contreras Rocha
// File: util.h
// Date: 27/02/20

#ifndef UTIL_H
#define UTIL_H

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
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
