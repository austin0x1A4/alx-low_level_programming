#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int rand(void) {
    static int first = 1;
    if (first) {
        first = 0;
        return 9;  // Your first winning number
    }
    return ((int (*)(void))dlsym(RTLD_NEXT, "rand"))();
}
