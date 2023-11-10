#include <stdio.h>

int isSubString(char input[], char subString[]) {
    int len = 0;
    while (subString[len] != '\0') {
        len++;
    }
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == subString[0]) {
            int j = 0;
            while (subString[j] != '\0' && subString[j] == input[i + j]) {
                j++;
            }
            
            if (j == len) {
                while (input[i] != '\0') {
                    input[i] = input[i + len];
                    i ++;
                }
                input[i + 1] = '\0';
                
                return 0;
            }
        }
    }
    
    return 1;
}

int main() {
    char input[101];
    char subString[101] = "cde";
    
    scanf("%100s", input);
    // scanf("%100s", subString);
    isSubString(input, subString);
    printf("%s\n", input);
    
    return 0;
}
