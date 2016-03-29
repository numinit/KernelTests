// i_hate_your_kernel.c
// You know your kernel sucks. Want to know how badly?

#include <comp421/yalnix.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNTOF(__x) ((sizeof(__x)/sizeof(0[__x])) / ((size_t)(!(sizeof(__x) % sizeof(0[__x])))))
#define STR(__cond) #__cond
#define ASSERT(__cond) \
    if (!(__cond)) { \
        fprintf(stderr, "FAILED: FUNCTION `%s`, LINE %d: " STR(__cond) "\n", __PRETTY_FUNCTION__,__LINE__); \
        Exit(-1); \
    } else { \
        fprintf(stderr, "PASSED: " STR(__cond) "\n"); \
    }

typedef int (*test_fn_t)(int);

static void barrier_wait(volatile int *cond) {
    while (*cond == 0);
    *cond = 0;
}

static void barrier_signal(volatile int *cond) {
    *cond = 1;
}

static int i_hate_your_exec(int id) {
    // All of these should fail
    ASSERT(Exec(NULL, NULL) == ERROR);
    ASSERT(Exec((void *)1, (void *)1) == ERROR);
}

test_fn_t test_functions[] = {
    i_hate_your_exec
};

int main(int argc, char **argv) {
    volatile int barrier[COUNTOF(test_functions)] = {0};
    for (int i = 0; i < COUNTOF(test_functions); i++) {
        if (Fork() == 0) {
            barrier_wait(&barrier[i]);
            return test_functions[i](i);
        }
    }

    for (int i = 0; i < COUNTOF(test_functions); i++) {
        barrier_signal(&barrier[i]);
    }

    while (true) {
        pid_t pid;
        int status;
        if ((pid = Wait(&status)) != ERROR) {
            fprintf(stderr, "process %d exited with status %d\n", pid, status);
        }
    }
}
