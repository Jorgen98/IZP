#include <stdio.h>

int main(void) {
	int arr_size = 5;
	double numbers[arr_size];

	printf("Select %d numbers: ", arr_size);
	for (int i = 0; i < arr_size; i++) {
		scanf("%lf", &numbers[i]);
	}
	
	printf("Reversed order: ");
	for (int i = arr_size - 1; i >= 0; i--) {
		printf("%.2lf ", numbers[i]);
	}
	printf("\n");

	return 0;
}
