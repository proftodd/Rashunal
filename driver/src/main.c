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
    char *rat_3_string = to_string(rat_3);
    printf("%s\n", "The sum is:");
    printf("%s\n", rat_3_string);

    printf("%s\n", "");

    Rashunal *z = n_Rashunal(0, 2);
    char *z_string = to_string(z);
    printf("%s\n", "Zero:");
    printf("%s\n", z_string);

    printf("%s\n", "");

    printf("%s\n", "Undefined:");
    Rashunal *u = n_Rashunal(1, 0);
    if (signal_sent == 0) {
        char *u_string = to_string(u);
        printf("%s\n", u_string);
        free(u_string);
    }
    signal_sent = 0;

    printf("%s\n", "");

    printf("%s\n", "Divide by zero:");
    Rashunal *q = r_div(rat_1, z);
    if (signal_sent == 0) {
        char *q_string = to_string(q);
        printf("%s\n", q_string);
        free(q_string);
    }
    signal_sent = 0;

    free(rat_1);
    free(rat_2);
    free(rat_3);
    free(rat_3_string);
    free(u);
    free(q);
    signal(SIGFPE, orig_handler);

    return 0;
}