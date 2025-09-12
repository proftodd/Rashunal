#pragma once
#include "rashunal.h"

#ifndef RASHUNAL_UTIL
#define RASHUNAL_UTIL

RASHUNAL_API int gcd(int a, int b);
RASHUNAL_API int lcm(int a, int b);

RASHUNAL_API int count_digits(const int n);
RASHUNAL_API int count_digits_radix(const int n, const int r);

#endif
