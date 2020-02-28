// See util.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: util.c
// Date: 27/02/20

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

#define OUTFILE "points.dat"

/* Private functions */

/**
 * Implementation of the first function.
 * 
 * @param time Time to evaluate.
 * @return Point at given time.
 */
static double firstSignal( double time ) {
	double result = 0.0;
	for ( int n = 1; n <= N; ++n ) 
		result += cos(2*PI*n*time) * sin(PI*n/2) / (PI * n);
	return result;
}

/**
 * Implementation of the second function.
 * 
 * @param time Time to evaluate.
 * @return Point at given time.
 */
static double secondSignal( double time ) {
	double result = 0.0;
	for ( int n = 1; n <= N; ++n )
		result += sin(2*PI*n*time) * sin(PI*n/2) / (PI*n*R*C * PI*n);
	return result;
}

/**
 * Sends specific commands to GNUPlot.
 */
static void createGraph(void) {
    char *commands[] = {
        "set xlabel 'Time(s)",
        "set ylabel 'Amplitude'",
        "plot 'points.dat' u 1:2 title 'First' with lines, '' u 1:3 title 'Second' with lines"
    };
    int length = sizeof(commands) / sizeof(char *);
    plot(commands, length);
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void processData( double *points, size_t samples ) {
	// Evalute arguments
	if ( points == NULL || samples <= 0 )
		return;

	// Clean up and calculations
	removeFile(OUTFILE);

	double results[3];
	for ( int i = 0; i < samples; ++i ) {
		results[0] = points[i];
		results[1] = firstSignal(points[i]);
		results[2] = secondSignal(points[i]);
		saveState(OUTFILE, results, 3);
	}

	// Plot results
	createGraph();
}
