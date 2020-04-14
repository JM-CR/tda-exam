// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 22/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main( int argc, char *argv[] ) {
    // Console arguments
    if ( argc != 3 )
        return 1;

    double tf = strtol(argv[1], NULL, 10);   
    printf("Tiempo final %.2lfs\n", tf);

    int samples = strtol(argv[2], NULL, 10);
    printf("Muestras %d\n\n", samples);

    // Create memory
    double *points = calloc(samples, sizeof(double));

    // Calculate points
    double value = 0.0;
    double slice = tf / samples;
    for ( int i = 0; i < samples; ++i, value += slice )
        points[i] = value;

    // Send to the engine
    processData(points, samples);

    return 0;
}
