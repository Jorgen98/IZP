#include <stdio.h>
    
int main() {
    int arr[] = {0, 1, 2, 3, 4}, *p_arr;

    p_arr = arr; //arr in itself points on first elem of array
    printf("0 indx value: %d\n", arr[0]);
    printf("0 indx value: %d\n", *p_arr);

    // Print second element in different ways
    printf("1 indx value: %d\n", arr[1]);
    printf("1 indx value: %d\n", *(p_arr + 1));

    // Print last element in different ways
    printf("4 indx value: %d\n", arr[4]);
    printf("4 indx value: %d\n", *(p_arr + 4));

    // Use pointer on array to print elements
    printf("Array values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *p_arr);
        p_arr++; // Move pointer on next element
    }
    
    // printf("%d\n", *p_arr); This can cause issues, because pointer now points on
    // element arr[5], but this elem does not exists
    // Always keep in mind the size of your array
    
    p_arr = arr; // So we have to reset the pointer on first elem of array
    
    int a = 2, b = 4, temp;
    // Switch elements on a,b indexes
    temp = *(p_arr + a); // temp = arr[a];
    *(p_arr + a) = *(p_arr + b); // arr[a] = arr[b];
    *(p_arr + b) = temp; // arr[b] = temp;
    
    printf("\nSwitched array values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}
