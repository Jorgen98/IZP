#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *str_init = "Hello World!";

int find(char *str, char *subStr) {
    int subStrLen = strlen(subStr), j = 0, i = 0;
    while (str[i] != '\0') {
        if (str[i] == subStr[0]) {
            j = 0;
            while (str[i + j] == subStr[j]) {
                j++;
            }
            
            if (j == subStrLen) {
                return i;
            }
        }
        i++;
    }
    
    return -1;
}

char *replace(char *str, char *oldStr, char* newStr) {
    int indx = find(str, oldStr);
    
    int strLen = strlen(str);
    int oldLen = strlen(oldStr);
    int newLen = strlen(newStr);
    int lenDiff = newLen - oldLen;
    
    char *newPtr = realloc(str, sizeof(char) * (strLen + lenDiff + 1));
    if (newPtr == NULL) {
        return str;
    }
    str = newPtr;
    
    for (int i = strLen + lenDiff; i >= (indx + oldLen); i --) {
        newPtr[i] = str[i - lenDiff];
    }
    
    for (int i = 0; i < newLen; i ++) {
        newPtr[indx + i] = newStr[i];
    }
    
    return newPtr;
}

int main() {
    char *str = malloc(strlen(str_init) + 1);
    if (str == NULL) {
        return 1;
    }
    strcpy(str, str_init);
    
    str = replace(str, "World", "Eleanora");
    
    printf("%s\n", str);
    //free(str);
    return 0;
}
