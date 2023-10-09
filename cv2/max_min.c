#include <stdio.h>

int main(void) {
	const int arr_size = 5;
	int numbers[arr_size];

	printf("Select %d numbers: ", arr_size);
	for (int i = 0; i < arr_size; i++) {
		scanf("%d", &numbers[i]);
	}

	int max = numbers[0];
	for (int i = 1; i < arr_size; i++) {
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}
	printf("%d is the maximum of the array values.\n", max);
	
	int min = numbers[0];
	for (int i = 1; i < arr_size; i++) {
		if (numbers[i] < min) {
			min = numbers[i];
		}
	}
	printf("%d is the minimum of the array values.\n", min);

	return 0;
}
