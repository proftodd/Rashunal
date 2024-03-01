#include <stdio.h>
#include <stdlib.h>
#include "rashunal.h"

int main(int argc, char *argv[])
{
    Rashunal *rat_1 = n_Rashunal(1, 2);
    Rashunal *rat_2 = n_Rashunal(1, 3);
    Rashunal *rat_3 = r_add(rat_1, rat_2);
    printf("%s\n", "The sum is:");
    printf("( %d / %d )\n", rat_3->numerator, rat_3->denominator);

    free(rat_1);
    free(rat_2);
    free(rat_3);

    return 0;
}