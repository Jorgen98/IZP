#include <stdio.h>

int main(void) {
	int num1, num2, num3;

	// Get multiple values at once
	printf("Select three integer numbers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

        // Count avarage value
        int avg;
        avg = (num1 + num2 + num3) / 3;

	printf("The avarage value of %d, %d, %d is: %d\n",
            num1, num2, num3, avg);

        // To get the exact value it is necessary to change the data type from int to double, i.e. to decimal numbers
        // Along with this, it is necessary to modify the calculation of the average itself to avoid overtyping
        // This issue, as well as other data types, will be discussed in more detail in the following lectures and exercises

        double ex_avg;
        ex_avg = (num1 + num2 + num3) / 3.0;

        printf("The exact avarage value of %d, %d, %d is: %f\n",
            num1, num2, num3, ex_avg);

	return 0;
}
