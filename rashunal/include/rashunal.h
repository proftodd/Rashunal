#pragma once

#ifdef _WIN32
#ifdef RASHUNAL_BUILD_DLL
#define RASHUNAL_API __declspec(dllexport)
#else
#define RASHUNAL_API __declspec(dllimport)
#endif
#else
#define RASHUNAL_API
#endif

#ifndef RASHUNAL
#define RASHUNAL

typedef struct
{
    const int numerator;
    const int denominator;
} Rashunal;

RASHUNAL_API Rashunal* n_Rashunal(int numerator, int denominator);
RASHUNAL_API Rashunal* ni_Rashunal(int numerator);
RASHUNAL_API Rashunal* nr_Rashunal(const Rashunal *r);

RASHUNAL_API Rashunal* r_add(const Rashunal *a, const Rashunal *b);
RASHUNAL_API Rashunal* r_add_some(const int rashunal_count, ...);
RASHUNAL_API Rashunal* r_sub(const Rashunal *a, const Rashunal *b);
RASHUNAL_API Rashunal* r_mul(const Rashunal *a, const Rashunal *b);
RASHUNAL_API Rashunal* r_mul_some(const int rashunal_count, ...);
RASHUNAL_API Rashunal* r_div(const Rashunal *a, const Rashunal *b);
RASHUNAL_API Rashunal* r_mds(const Rashunal *a, const Rashunal *b, const Rashunal *pivot, const Rashunal *base);
RASHUNAL_API Rashunal* r_inv(const Rashunal *a);

RASHUNAL_API int printed_length(const Rashunal *a);
RASHUNAL_API char* to_string(const Rashunal *a);
RASHUNAL_API char* to_padded_string(const Rashunal *a, int length);

RASHUNAL_API int r_cmp(const Rashunal *a, const Rashunal *b);

#endif
