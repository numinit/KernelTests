#include <stdbool.h>
#include <stdio.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>
#define reduction 1000000

int main(int argc, char **argv) {
    pid_t pid;
    if ((pid = Fork()) == 0) {
        fprintf(stderr, "we're in the child now: PID %d\n", GetPid());
        long reduce_child_output = reduction;
        while(true) {
            reduce_child_output--;
            if (reduce_child_output == 0) {
                reduce_child_output = reduction;
                fprintf(stderr, "we're looping inside the child");
            }
        }

    } else {
        fprintf(stderr, "we're in the parent (PID %d) now, and forked PID %d\n", GetPid(), pid);
        long reduce_parent_output = reduction;
        while(true) {
            reduce_parent_output--;
            if (reduce_parent_output == 0) {
                reduce_parent_output = reduction;
                fprintf(stderr, "we're looping inside the parent");
            }
        }
    }
}
