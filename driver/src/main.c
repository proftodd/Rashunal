#include <stdio.h>
#include <stdlib.h>
#include "rashunal.h"

int main(int argc, char *argv[])
{
    Rashunal *rat_1 = n_Rashunal(1, 2);
    Rashunal *rat_2 = n_Rashunal(1, 3);
    Rashunal *rat_3 = r_add(rat_1, rat_2);
    printf("The sum is:");

    return 0;
}