#include <stdio.h>
#include <stdlib.h>

unsigned int sum(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum(n - 1);
}

int main(int argc, char **argv) {
    unsigned int n;
    if (argc < 2)
        return 1;
    n = strtoul(argv[1], NULL, 10);

    printf("Sum is %u\n", sum(n));
    return 0;
}

