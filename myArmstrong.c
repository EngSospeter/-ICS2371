//SOSPETER NG'ANG'A
//ENE212-0061/2021

#include <stdio.h>

int main() {
    int num, originalNum, remainder, digits = 0, result = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num;

    // Counting the number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        digits++;
    }

    originalNum = num;

    // Checking if the number is an Armstrong number
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += remainder * remainder * remainder;
        originalNum /= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}