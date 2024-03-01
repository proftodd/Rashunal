#include <stdlib.h>
#include "rashunal.h"
#include "rashunal_util.h"

Rashunal* n_Rashunal(int numerator, int denominator)
{
    Rashunal* result = malloc(sizeof(Rashunal));
    int abs_d = abs(denominator);
    int g = gcd(abs(numerator), abs_d);
    result->numerator = (denominator >= 0 ? 1 : -1) * numerator / g;
    result->denominator = abs_d / g;
    return result;
}

Rashunal* ni_Rashunal(int an_int)
{
    return n_Rashunal(an_int, 1);
}

Rashunal* r_add(Rashunal* a, Rashunal* b)
{
    int new_d = lcm(a->denominator, b->denominator);
    return n_Rashunal(a->numerator * new_d / a->denominator + b->numerator * new_d / b->denominator, new_d);
}

Rashunal* r_sub(Rashunal* a, Rashunal* b)
{
    int new_d = lcm(a->denominator, b->denominator);
    return n_Rashunal(a->numerator * new_d / a->denominator - b->numerator * new_d / b->denominator, new_d);
}

Rashunal* r_mul(Rashunal* a, Rashunal* b)
{
    return n_Rashunal(a->numerator * b->numerator, a->denominator * b->denominator);
}

Rashunal* r_div(Rashunal* a, Rashunal* b)
{
    return n_Rashunal(a->numerator * b->denominator, a->denominator * b->numerator);
}

Rashunal* r_inv(Rashunal* a)
{
    return n_Rashunal(a->denominator, a->numerator);
}