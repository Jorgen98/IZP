#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

int findMinInx(int *arr, int idx) {
    int min = idx;
    
    for (int i = idx + 1; i < ARR_SIZE; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    
    return min;
}

void sort(int *arr) {
    int min = 0, tmp = 0;
    for (int i = 0; i < ARR_SIZE; i++) {
        min = findMinInx(arr, i);
        
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

int main() {
    int *arr = malloc(sizeof(int) * ARR_SIZE);
    if (arr == NULL) {
        return 1;
    }
    
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("Provide %d elem: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    sort(arr);
    
    printf("Ordered array: ");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return 0;
}
