#include <stdio.h>

#define SIZE 10

void modifyArr(int *arr, int newArr[]) {
    for (int i = 0; i < SIZE; i++) {
        if (i == 0) {
            newArr[i] = arr[i] + arr[i + 1]; // *(newArr + i) = *(arr + i) + *(arr + i + 1);
        } else if (i == (SIZE - 1)) {
            newArr[i] = arr[i - 1] + arr[i]; // *(newArr + i) = *(arr + i - 1) + *(arr + i);
        } else {
            newArr[i] = arr[i - 1] + arr[i + 1]; // *(newArr + i) = *(arr + i - 1) + *(arr + i + 1); 
        }
    }
}

void printArr(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(arr + i)); // printf("%d ", arr[i]);
    }
}

int main() {
    int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int newArr[SIZE];
    
    modifyArr(arr, newArr);
    printArr(newArr);
    
    printf("\n");
    return 0;
}
