#include <stdio.h>

int main(void) {
	int num1, num2, num3;

        // Get user input
	printf("Select three integer numbers: ");
	scanf("%d", &num1);
        scanf("%d", &num2);
        scanf("%d", &num3);

        // Find maximum number and print it to STDOUT
	if (num1 > num2) {
		if (num1 > num3) {
			printf("The maximum number is: %d\n", num1);
		} else {
			printf("The maximum number is: %d\n", num3);
		}
	} else {
		if (num2 > num3) {
			printf("The maximum number is: %d\n", num2);
		} else {
			printf("The maximum number is: %d\n", num3);
		}
	}

	return 0;
}
