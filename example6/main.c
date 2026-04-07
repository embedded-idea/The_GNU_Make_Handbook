#include "mathlib.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    argc = argc; /* silence unused parameter warning */ 
    argv = argv; /* silence unused parameter warning */
    int a = 10, b = 5;
    printf("add: %d\n", add(a, b));
    printf("sub: %d\n", sub(a, b));
    printf("mul: %d\n", mul(a, b));
    return 0;
}