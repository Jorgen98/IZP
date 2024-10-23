#include <stdio.h>

#define MX_ROWS 10
#define MX_COLS 10

void clearArr(int arr2D[MX_ROWS][MX_COLS]) {
    for (int i = 0; i < MX_ROWS; i++) {
        for (int j = 0; j < MX_COLS; j++) {
            arr2D[i][j] = 0;
        }
    }
}

void changeArr(int arr2D[MX_ROWS][MX_COLS], int type) {
    for (int i = 0; i < MX_ROWS; i++) {
        for (int j = 0; j < MX_COLS; j++) {
            if ((i <= j && type) || (i >= j && !type)) {
                arr2D[i][j] = 1;
            }
        }
    }
}

void printArr(int arr2D[MX_ROWS][MX_COLS]) {
    for (int i = 0; i < MX_ROWS; i++) {
        for (int j = 0; j < MX_COLS; j++) {
            printf("%d ", arr2D[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr2D[MX_ROWS][MX_COLS];
    int input = 0;
    
    printf("Provide type of result matrix: ");
    scanf("%d", &input);
    
    clearArr(arr2D);
    changeArr(arr2D, input);
    printArr(arr2D);
    
    return 0;
}
