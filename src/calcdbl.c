#include <math.h>
#include <stdio.h>
#include "calc.h"

double num_fraction(long int a, long int b)
{
    if (b == 0)
    {
        // Handle division by zero error
        fprintf(stderr, "Error: Division by zero\n");
        return NAN; // Return Not-A-Number to indicate error
    }
    return (double)a / b;
}

double square_root(long int a)
{
    if (a < 0)
    {
        // Handle negative number error
        fprintf(stderr, "Error: Negative number\n");
        return NAN; // Return Not-A-Number to indicate error
    }
    return sqrt(a);
}
