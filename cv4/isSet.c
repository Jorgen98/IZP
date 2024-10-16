#include <stdio.h>

int isSet(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    
    return 0;
}

int main() {
    int arrSize = 5;
    int arr[arrSize];
    
    printf("Select %d numbers for the array: ", arrSize);
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (!isSet(arr, arrSize)) {
        printf("Provided array is set");
    } else {
        printf("Provided array is not set");
    }
    
    printf("\n");
    return 0;
}
