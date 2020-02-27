// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 22/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define SAMPLES 10000
#define TF 5.0

int main(void) {

    // Create memory
    double *points = calloc(SAMPLES, sizeof(double));

    // Calculate points
    double value = 0.0;
    double slice = TF / SAMPLES;
    for ( int i = 0; i < SAMPLES; ++i, value += slice )
        points[i] = value;

    // Send to the engine
    processData(points, SAMPLES);

    return 0;
}