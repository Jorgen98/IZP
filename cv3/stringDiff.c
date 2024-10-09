#include <stdio.h>

int main() {
    char stringA[101];
    char stringB[101];
    printf("Select first string: ");
    scanf("%100s", stringA);
    
    printf("Select second string: ");
    scanf("%100s", stringB);
    
    int index = 0;
    while (stringA[index] != '\0' && stringB[index] != '\0') {
        if (stringA[index] != stringB[index]) {
            printf("Strings are different");
            return 0;
        }
        index++;
    }
    
    if (stringA[index] == '\0' && stringB[index] == '\0') {
        printf("Strings are same");
    } else {
        printf("Strings are different");
    }
    
    return 0;
}
