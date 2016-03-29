#include <comp421/yalnix.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    fprintf(stderr, "running %s\n", argv[0]);
    volatile int *a = malloc(4096);
    volatile int *b = malloc(4096);
    volatile int *c = malloc(4096);
    volatile int *d = malloc(4096);

    *a = 42;
    *b = 43;
    *c = 44;
    *d = 45;

    free((void *)a);
    free((void *)b);
    free((void *)c);
    free((void *)d);
}
