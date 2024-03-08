#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "rashunal.h"
#include "rashunal_util.h"

Rashunal* n_Rashunal(int numerator, int denominator)
{
    if (denominator == 0) {
        raise(SIGFPE);
    }

    if (numerator == 0) {
        denominator = 1;
    }

    int abs_d = abs(denominator);
    int g = gcd(abs(numerator), abs_d);
    int n = (denominator >= 0 ? 1 : -1) * numerator / g;
    int d = abs_d / g;
    Rashunal r =
    {
        numerator = n,
        denominator = d
    };
    Rashunal *result = malloc(sizeof(Rashunal));
    if (result) {
        memcpy(result, &r, sizeof(Rashunal));
    }
    return result;
}

Rashunal* ni_Rashunal(int an_int)
{
    return n_Rashunal(an_int, 1);
}

Rashunal* r_add(Rashunal *a, Rashunal *b)
{
    int new_d = lcm(a->denominator, b->denominator);
    return n_Rashunal(a->numerator * new_d / a->denominator + b->numerator * new_d / b->denominator, new_d);
}

Rashunal* r_sub(Rashunal *a, Rashunal *b)
{
    int new_d = lcm(a->denominator, b->denominator);
    return n_Rashunal(a->numerator * new_d / a->denominator - b->numerator * new_d / b->denominator, new_d);
}

Rashunal* r_mul(Rashunal *a, Rashunal *b)
{
    return n_Rashunal(a->numerator * b->numerator, a->denominator * b->denominator);
}

Rashunal* r_div(Rashunal *a, Rashunal *b)
{
    return n_Rashunal(a->numerator * b->denominator, a->denominator * b->numerator);
}

Rashunal* r_inv(Rashunal* a)
{
    return n_Rashunal(a->denominator, a->numerator);
}