#include <stdio.h>

int main() {
    char string[101];
    printf("Select string: ");
    scanf("%100s", string);
    
    int index = 0;
    while (string[index] != '\0') {
        if (string[index] == 'a') {
            string[index] = '0';
        } else if (string[index] == 'b') {
            string[index] = '1';
        }
        index++;
    }
    
    printf("New string is: %s", string);
    
    return 0;
}
