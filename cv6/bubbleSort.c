#include <stdio.h>

int main() {
    int arrSize = 5;
    double arr[] = {1, 33, 4, 0, 12}, *p_arr, temp;
    
    p_arr = arr;
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (*(p_arr + i) < *(p_arr + j)) {
                temp = *(p_arr + i);
                *(p_arr + i) = *(p_arr + j);
                *(p_arr + j) = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    p_arr = arr;
    for (int i = 0; i < arrSize; i++, p_arr++) {
        printf("%.2lf ", *p_arr);
    }
    
    printf("\n");
    return 0;
}
