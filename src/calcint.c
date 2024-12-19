#include "calc.h"

long int add(long int a, long int b)
{
    return a + b;
}

long int difference(long int a, long int b)
{
    return a - b;
}

long int product(long int a, long int b)
{
    return a * b;
}

long int factorial(long int a)
{
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return a * factorial(a - 1);
    }
}
