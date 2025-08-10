#ifndef RASHUNAL
#define RASHUNAL

typedef struct
{
    const int numerator;
    const int denominator;
} Rashunal;

Rashunal* n_Rashunal(int numerator, int denominator);
Rashunal* ni_Rashunal(int numerator);

Rashunal* r_add(const Rashunal *a, const Rashunal *b);
Rashunal* r_sub(const Rashunal *a, const Rashunal *b);
Rashunal* r_mul(const Rashunal *a, const Rashunal *b);
Rashunal* r_div(const Rashunal *a, const Rashunal *b);
Rashunal* r_mds(const Rashunal *a, const Rashunal *b, const Rashunal *pivot, const Rashunal *base);
Rashunal* r_inv(const Rashunal *a);

int printed_length(const Rashunal *a);
char* to_string(const Rashunal *a);
char* to_padded_string(const Rashunal *a, int length);

int r_cmp(const Rashunal *a, const Rashunal *b);

#endif
