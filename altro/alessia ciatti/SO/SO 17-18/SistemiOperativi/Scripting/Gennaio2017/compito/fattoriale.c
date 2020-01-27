#include <stdio.h>
#include <stdlib.h>

// recursive version
unsigned int fact_rec(unsigned int n) {
    if (n <=1) return 1;
    else return n * fact_rec(n-1);
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
    printf("[%u] ric: %u iter: %u\n", n, fact_rec(n), fact_iter(n));

    return 0;
}