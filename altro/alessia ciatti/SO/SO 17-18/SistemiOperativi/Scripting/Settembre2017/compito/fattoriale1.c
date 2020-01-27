#include <stdio.h>
#include <stdlib.h>

// recursive version
unsigned int fact_rec(unsigned int n) {
    unsigned int r; 
    if (n <=1) 
        r = 1;
    else {
        unsigned int i = fact_rec(n-1);
        r = n * i;
    }
    return r;
}

// iterative version
unsigned int fact_iter(unsigned int n) {
    unsigned int k, r=2;
    for (k = 2; k <= n; ++k) {
        r = r * k;
    }
    return r;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
    printf("Syntax: %s <n>\n", argv[0]);
        return 1;
    }

    unsigned int n = atoi(argv[1]);
    printf("[%u]\n", n);
    printf("iter: %u\n", fact_iter(n));
    printf("ric: %u\n", fact_rec(n));

    return 0;
}