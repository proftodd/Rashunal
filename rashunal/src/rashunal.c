#include <signal.h>
#include <stdio.h>
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
        return result;
    } else {
        return NULL;
    }
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

Rashunal* r_mds(Rashunal *a, Rashunal *b, Rashunal *pivot, Rashunal *base)
{
    int n1 = a->numerator * base->numerator;
    int d1 = a->denominator * base->denominator;

    int n2 = b->numerator * pivot->numerator;
    int d2 = b->denominator * pivot->denominator;

    int n3 = n1 * d2 - n2 * d1;
    int d3 = d1 * d2;

    return n_Rashunal(n3 * base->denominator, d3 * base->numerator);
}

int printed_length(Rashunal *a)
{
    if (a->numerator == 0) {
        return 1;
    } else if (a->denominator == 1) {
        return snprintf(NULL, 0, "%d", a->numerator);
    } else {
        return snprintf(NULL, 0, "%d / %d", a->numerator, a->denominator);
    }
}

char* to_string(Rashunal *a)
{
    int r_length = printed_length(a);
    char *s = malloc(sizeof(char) * (r_length + 1));
    if (!s) {
        return NULL;
    }

    int copied_char_count;
    if (a->numerator == 0) {
        copied_char_count = snprintf(s, r_length + 1, "0");
    } else if (a->denominator == 1) {
        copied_char_count = snprintf(s, r_length + 1, "%d", a->numerator);
    } else {
        copied_char_count = snprintf(s, r_length + 1, "%d / %d", a->numerator, a->denominator);
    }

    if (copied_char_count != r_length) {
        free(s);
        return NULL;
    }
    return s;
}

char* to_padded_string(Rashunal *a, int length)
{
    int actual_length = abs(length);
    char *s = malloc(sizeof(char) * (actual_length + 1));
    if (!s) {
        return NULL;
    }

    char fmt[100];
    sprintf(fmt, "%%%ds", length);

    char *unpadded = to_string(a);
    int copied_char_count = snprintf(s, actual_length + 1, fmt, unpadded);
    free(unpadded);
    if (copied_char_count != actual_length) {
        free(s);
        return NULL;
    }

    return s;
}