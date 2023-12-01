#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ull;

ull nf = 0;
ull *results;

ull fibFast(ull n)
{
    nf++;
    if (results[n - 1] == 0) {
        results[n - 1] = fibFast(n - 1);
    }
    if (results[n - 2] == 0) {
        results[n - 2] = fibFast(n - 2);
    }

    return results[n - 1] + results[n - 2];
}

int main(int argc, char **argv)
{
    ull n;
    if (argc < 2)
        return 1;
    n = strtoul(argv[1], NULL, 10);
    
    results = calloc(n, sizeof(ull));
    
    if (results == NULL) {
        return -1;
    }
    
    results[0] = 0;
    results[1] = 1;
    results[2] = 1;

    printf("fib(%llu) = %llu\n", n, fibFast(n));
    printf("nf = %llu\n", nf);
    
    free(results);
    return 0;
}

