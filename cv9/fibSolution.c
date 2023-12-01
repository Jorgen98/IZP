/**
 * Kostra programu pro vypocet Fibonacciho cisel
 * 2020, Ales Smrcka
 */
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ull;

// Proměnná pro počítání počtu volání funkce
ull nf = 0;
/**
 * Fib(n) = 
 *  0                   n=0
 *  1                   n=1
 *  Fib(n-1)+Fib(n-2)   n>1
 *
 * Naprogramujte funkci rekurzivne.
 * Zjistete, kolikrat byla funkce volana.
 */
ull fib(ull n)
{
    nf++;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char **argv)
{
    ull n;
    if (argc < 2)
        return 1;
    n = strtoul(argv[1], NULL, 10);

    printf("fib(%llu) = %llu\n", n, fib(n));
    printf("nf = %llu\n", nf);
    return 0;
}

