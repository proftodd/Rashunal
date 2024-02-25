#ifndef RASHUNAL
#define RASHUNAL

typedef struct
{
    int numerator;
    int denominator;
} Rashunal;

int gcd(int a, int b);
int lcm(int a, int b);

Rashunal* n_Rashunal(int numerator, int denominator);
Rashunal* ni_Rashunal(int numerator);

Rashunal* r_add(Rashunal* a, Rashunal* b);
Rashunal* r_sub(Rashunal* a, Rashunal* b);
Rashunal* r_mul(Rashunal* a, Rashunal* b);
Rashunal* r_div(Rashunal* a, Rashunal* b);
Rashunal* r_inv(Rashunal* a);

#endif
