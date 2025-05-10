#include "rashunal_util.h"

int gcd(int a, int b)
{
    if (a == 0) { return b; }
    if (b == 0) { return a; }
    if (a < b) { return gcd(a, b % a); }
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int count_digits(const int n)
{
    int nn = n;
    int count;
    if (nn < 0) {
        nn *= -1;
        count = 2;
    } else {
        count = 1;
    }
    while (nn >= 10) {
        nn /= 10;
        ++count;
    }
    return count;
}