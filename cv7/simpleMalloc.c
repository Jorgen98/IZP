#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Dynamic vs static allocation for 1 integer
    int a;
    int *p_a;
    
    p_a = malloc(sizeof(int));
    
    if (p_a == NULL) {
        return 1;
    }
    
    a = 5;
    *p_a = a;
    
    printf("%d\n", *p_a);
    
    if (p_a != NULL) {
        free(p_a);
    }
    
    // Dynamic vs static allocation for 5 items array
    char arr[5] = {"ahoj"};
    char *p_arr;
    
    p_arr = malloc(sizeof(char) * 5); // Do not forget to alloc memory for '\0'
    
    if (p_arr == NULL) {
        return 1;
    }
    
    // Copy string by chars with '\0' on the end
    for (int i = 0; i < 5; i++) {
        *(p_arr + i) = arr[i];
    }
    
    printf("%s\n", p_arr);
    
    if (p_arr != NULL) {
        free(p_arr);
    }
    
    return 0;
}
