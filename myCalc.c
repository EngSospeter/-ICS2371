//SOSPETER NG'ANG'A
//ENE212-0061/2021
#include <stdio.h>

int main() {
    char operator;
    int num1, num2, result;

    // Input operator from user
    printf("Enter operator (+ or -): ");
    scanf(" %c", &operator);
    
    // Input two numbers from user
    printf("Enter two numbers(separating them using a single space): ");
    scanf("%d %d", &num1, &num2);

    // Perform operation based on operator
    if (operator == '+') {
        result = num1 + num2;
        printf("Result: %d\n", result);
    } else if (operator == '-') {
        result = num1 - num2;
        printf("Result: %d\n", result);
    } else {
        printf("Invalid operator!\n");
    }

    return 0;
}