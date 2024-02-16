//SOSPETER NG'ANG'A
//ENE212-0061/2021

#include <stdio.h>
#include <stdlib.h>

int main() {
    char operator;
    int num1, num2, result;
    int validOperator = 1; // Flag to track if the operator is valid
    int validInput = 1; // Flag to track if the input numbers are valid

    

    // Input operator from user
    printf("Enter operator (+, -, *, or /): ");
    scanf(" %c", &operator);

    // Check if the operator is valid
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
        // Input two numbers from user
        printf("Enter two numbers: ");
        
        // Check if the input numbers are integers
        if (scanf("%d %d", &num1, &num2) != 2) {
            printf("Invalid input! Please enter two integers.\n");
            validInput = 0; // Set flag to indicate invalid input
        }

        // Perform operation only if both operator and input numbers are valid
        if (validInput) {
            // Perform operation based on operator
            if (operator == '+') {
                result = num1 + num2;
                printf("Result: %d\n", result);
            } else if (operator == '-') {
                result = num1 - num2;
                printf("Result: %d\n", result);
            } else if (operator == '*') {
                result = num1 * num2;
                printf("Result: %d\n", result);
            } else { // operator == '/'
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                } else {
                    printf("Division by zero is not allowed!\n");
                }
            }
        }
    } else {
        printf("Invalid operator!\n");
        validOperator = 0; // Set flag to indicate invalid operator
    }

    return 0;
}