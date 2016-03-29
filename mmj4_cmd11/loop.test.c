#include <stdio.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>

int main(int argc, char **argv) {
    fprintf(stderr, "running %s\n", argv[0]);
    for (int i=5; i<8; i++) {
        fprintf(stderr, "hello world - I'm the loop-delay init function!\n");
        fprintf(stderr, "My PID is %d!\n", GetPid());
        Delay(i);
    }
    fprintf(stderr, "goodbye world - loop-delay init is done!\n");
 
}
