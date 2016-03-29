#include <comp421/yalnix.h>
#include <stdio.h>

int main(int argc, char **argv) {
    fprintf(stderr, "%s is executing %s\n", argv[0], argv[1]);
    Exec(argv[1], &argv[1]);
}
