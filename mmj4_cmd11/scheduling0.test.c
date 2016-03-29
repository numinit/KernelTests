#include <stdbool.h>
#include <stdio.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>
#define reduction 1000000
long update_count(long, int);

int main(int argc, char **argv) {
    pid_t my_pid;
    Fork();
    Fork();
    Fork();
    Fork();
    my_pid = GetPid();
    int counter = reduction;
    while(true) {
        counter = update_count(counter, my_pid);
        if (my_pid == 2 || my_pid == 7) {
            Delay(3);
        }

        if (my_pid == 4) {
            Delay(5);
        }
        
        if (my_pid == 2) {
            Delay(1);
        }
    }
}

long update_count(long reduce_output, int pid) {
    reduce_output--;
    if (reduce_output == 0) {
        reduce_output = reduction;
        fprintf(stderr, "we're looping inside %02d! ", pid);
    }
    return reduce_output;
}
