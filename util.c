// See util.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: util.c
// Date: 17/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <math.h>
#include "util.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private macros and constants */

#define PI 3.1416
#define N 20
#define R 1000
#define C 10E-6

/* Private global variables */

static size_t sampleSize;   // Number of results

/* Private functions */

/**
 * Implementation for the 'f(t)' function.
 * 
 * @param t Time to evaluate.
 * @return Point at given time.
 */
static double firstSignal( double t ) {
	return 1.0;
}

/**
 * Implementation for the 'f(t)' function.
 * 
 * @param t Time to evaluate.
 * @return Point at given time.
 */
static double secondSignal( double t ) {
	return 1.0;
}

/**
 * Sends specific commands to GNUPlot.
 */
static void createGraph( void ) {
    char *commands[] = {
        "set title 'Euler approximation'",
        "set xlabel 'Time (s)'",
        "set ylabel 'Samples",
        "plot 'solution.dat' u 1:2 title '' with lines"
    };
    int length = sizeof(commands) / sizeof(char *);
    plot(commands, length);
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void setSampleSize( unsigned int size ) {
	sampleSize = size;
}

void processData( double *points ) {
	// Evalute arguments
	if ( points == NULL || finalTime == 0.0 )
		return;

	// Clean up and calculations
	removeFile("points.dat");
	firstSignal(points);
	secondSignal(points);

	// Plot results
	createGraph();
}
