#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Wrong number of arguments provided.");
        return 1;
    }
    
    int len = 0, curLen = 0, resIndex = 0, curIndex = 0;
    for (int i = 1; i < 4; i++) {
        int index = 0;
        while (argv[i][index] != '\0') {
            curLen++;
            index++;
        }
        
        if (len < curLen) {
            resIndex = i;
            len = curLen;
        }
        
        curLen = 0;
    }
    
    printf("The longest string is: %s", argv[resIndex]);
    
    return 0;
}
