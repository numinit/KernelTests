#include <stdbool.h>
#include <stdio.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>

int main(int argc, char **argv) {
    pid_t pid;
    if ((pid = Fork()) == 0) {
        fprintf(stderr, "we're in the child now: PID %d\n", GetPid());
        if ((pid = Fork()) == 0) {
            fprintf(stderr, "child's child: pid %d\n", GetPid());
            if ((pid = Fork()) == 0) {
                fprintf(stderr, "child's child's child: pid %d\n", GetPid());
                while (true) {
                    fprintf(stderr, "child's child's child (PID %d) delaying\n", GetPid());
                    Delay(5);
                }
            } else {
                fprintf(stderr, "child's child (PID %d) forked PID %d\n", GetPid(), pid);
            }
        } else {
            fprintf(stderr, "child (PID %d) forked PID %d\n", GetPid(), pid);
            while (true) {
                fprintf(stderr, "child (PID %d) delaying\n", GetPid());
                Delay(3);
            }
        }
    } else {
        fprintf(stderr, "we're in the parent (PID %d) now, and forked PID %d\n", GetPid(), pid);
    }
}
