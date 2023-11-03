#include <stdio.h>

void loadString(char *arr) {
    printf("Provide string:");
    scanf("%100s", arr);
}

void loadIndexes(int *a, int *b) {
    printf("Provide first index:");
    scanf("%d", a);
    printf("Provide second index:");
    scanf("%d", b);
}

void switchChars(int a, int b, char *arr) {
    char temp = *(arr + a); //char temp = arr[a];
    *(arr + a) = *(arr + b); //arr[a] = arr[b];
    *(arr + b) = temp; //arr[b] = temp;
}

int main() {
    char arr[101];
    int a, b;
    
    loadString(arr);
    loadIndexes(&a, &b);
    switchChars(a, b, arr);
    
    printf("New string is: %s\n", arr);
    return 0;
}
