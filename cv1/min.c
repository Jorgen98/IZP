#include <stdio.h>

int main(void) {
	int num1, num2, num3;

	// Get multiple values at once
	printf("Select three integer numbers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

        // Find the minimum number
	int min_num = num1;
	if (num2 < min_num) {
		min_num = num2;
	}
	if (num3 < min_num) {
		min_num = num3;
	}
	printf("The minimum number of %d, %d, %d is: %d\n",
            num1, num2, num3, min_num);

	return 0;
}
