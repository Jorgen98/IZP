#include <stdio.h>

int main(void) {
	const int arr_size = 3;
	double numbers[arr_size];
	
	printf("Select %d numbers: ", arr_size);
	for (int i = 0; i < arr_size; i++) {
		scanf("%lf", &numbers[i]);
	}

	double sum = numbers[0];
	for (int i = 1; i < arr_size; i++) {
		sum += numbers[i];
	}
	double avg = sum / (double)arr_size;

	printf("%.2lf is the sum of the array values.\n", sum);
	printf("%lf is the average of the array values.\n", avg);

	return 0;
}
