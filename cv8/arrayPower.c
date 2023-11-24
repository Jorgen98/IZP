#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

int main() {
    int *arr = malloc(sizeof(int) * ARR_SIZE);
    if (arr == NULL) {
        return 1;
    }
    
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = i * i;
    }
    
    int *newArr = realloc(arr, sizeof(int) * ARR_SIZE * 2);
    if (newArr == NULL) {
        free(arr);
        return 1;
    }
    
    arr = newArr;
    
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i + ARR_SIZE] = arr[i] * arr[i];
    }

    for (int i = 0; i < ARR_SIZE * 2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return 0;
}
