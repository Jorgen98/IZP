#include <stdio.h>

int countElemsValue(int arr[], int arrSize) {
    int value = 0;
    for (int i = 0; i < arrSize; i++) {
        value += arr[i];
    }
    
    return value;
}

void compareArrs(int arr1[], int arr2[], int arrSize) {
    int arr1Value = countElemsValue(arr1, arrSize);
    int arr2Value = countElemsValue(arr2, arrSize);
    
    if (arr1Value > arr2Value) {
        printf("Sum of elems is greater in 1st array");
    } else if (arr1Value < arr2Value)  {
        printf("Sum of elems is greater in 2nd array");
    } else {
        printf("Sum of elems are equal");
    }
    
    printf("\n");
}

int main() {
    int arrSize = 5;
    int arr1[arrSize];
    int arr2[arrSize];
    
    printf("Select %d numbers for the first array: ", arrSize);
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf ("Select %d numbers for the second array: ", arrSize);
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &arr2[i]);
    }
    
    compareArrs(arr1, arr2, arrSize);
    return 0;
}
