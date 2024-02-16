//SOSPETER NG'ANG'A
//ENE212-0061/2021

#include <stdio.h>

int main() {
    int n, reversedN = 0, originalN, remainder;

    // Input the number from the user
    printf("Enter an integer: ");
    scanf("%d", &n);

    originalN = n; // Save the original number

    // Reverse the number
    while (n != 0) {
        remainder = n % 10;
        reversedN = reversedN * 10 + remainder;
        n /= 10;
    }

    // Check if the reversed number is equal to the original number
    if (originalN == reversedN)
        printf("%d is a palindrome.\n", originalN);
    else
        printf("%d is not a palindrome.\n", originalN);

    return 0;
}