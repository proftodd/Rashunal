#include <stdio.h>
#include <stdlib.h>
#include "rashunal.h"

static int signal_sent;
void fpe_handler(int sig)
{
    signal_sent = 1;
    printf("%s\n", "Oops! you tried to divide by zero");
}

int main(int argc, char *argv[])
{
    void (*orig_handler)(int);
    signal_sent = 0;
    orig_handler = signal(SIGFPE, fpe_handler);

    Rashunal *rat_1 = n_Rashunal(1, 2);
    Rashunal *rat_2 = n_Rashunal(1, 3);
    Rashunal *rat_3 = r_add(rat_1, rat_2);
    printf("%s\n", "The sum is:");
    printf("( %d / %d )\n", rat_3->numerator, rat_3->denominator);

    printf("%s\n", "");

    Rashunal *z = n_Rashunal(0, 2);
    printf("%s\n", "Zero:");
    printf("( %d / %d)\n", z->numerator, z->denominator);

    printf("%s\n", "");

    printf("%s\n", "Undefined:");
    Rashunal *u = n_Rashunal(1, 0);
    if (signal_sent == 0) {
        printf("( %d / %d )\n", u->numerator, u->denominator);
    }
    signal_sent = 0;

    printf("%s\n", "");

    printf("%s\n", "Divide by zero:");
    Rashunal *q = r_div(rat_1, z);
    if (signal_sent == 0) {
        printf("( %d / %d)\n", z->numerator, z->denominator);
    }
    signal_sent = 0;

    free(rat_1);
    free(rat_2);
    free(rat_3);
    free(u);
    free(q);
    signal(SIGFPE, orig_handler);

    return 0;
}