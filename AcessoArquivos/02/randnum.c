#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
#define PFLOAT 100.0

int main () {

    srand ((unsigned int)time(NULL));
    
    float a = PFLOAT;
    for (int i = 0; i < MAX; i++)
        printf ("%f\n", ((float)rand()/(float)(RAND_MAX)) * a);

    return 0;
}