#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Select string length: ");
    
    int strLen = 0;
    scanf("%d", &strLen);
    
    char *str = malloc(sizeof(char) * (strLen + 1));
    if (str == NULL) {
        return 1;
    }
    
    printf("Select string: ");
    scanf("%s", str);
    str[strLen] = '\0';
    
    int count = 0;
    char occ;
    
    printf("Select char: ");
    scanf("\n%c", &occ);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == occ) {
            count++;
        }
    }
    
    printf("Number of chars '%c' in string '%s' is %d\n", occ, str, count);
    
    free(str);

    return 0;
}
