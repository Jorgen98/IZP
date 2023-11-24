#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Select num of array elems: ");
    
    int arrSize = 0;
    scanf("%d", &arrSize);
    
    int *arr = malloc(sizeof(int) * arrSize);
    if (arr == NULL) {
        return 1;
    }
    
    for (int i = 0; i < arrSize; i++) {
        printf("Provide %d elem: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Reversed order: ");
    for (int i = arrSize - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return 0;
}
