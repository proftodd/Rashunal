#ifndef RASHUNAL
#define RASHUNAL

typedef struct
{
    const int numerator;
    const int denominator;
} Rashunal;

Rashunal* n_Rashunal(int numerator, int denominator);
Rashunal* ni_Rashunal(int numerator);

Rashunal* r_add(Rashunal *a, Rashunal *b);
Rashunal* r_sub(Rashunal *a, Rashunal *b);
Rashunal* r_mul(Rashunal *a, Rashunal *b);
Rashunal* r_div(Rashunal *a, Rashunal *b);
Rashunal* r_mds(Rashunal *a, Rashunal *b, Rashunal *pivot, Rashunal *base);
Rashunal* r_inv(Rashunal *a);

int printed_length(Rashunal *a);
char* to_string(Rashunal *a);
char* to_padded_string(Rashunal *a, int length);

#endif
