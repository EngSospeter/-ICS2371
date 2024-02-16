//SOSPETER NG'ANG'A
//ENE212-0061/2021

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int addition(int num1, int num2);
int subtraction(int num1, int num2);
int multiplication(int num1, int num2);
int division(int num1, int num2);

int main() {
    char operator;
    int num1, num2, result;

    printf("Enter operator (+, -, *, or /): ");
    scanf(" %c", &operator);
    
    printf("Enter two numbers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input! Please enter two integers.\n");
        return 1;
    }

// Perform operation based on operator
    if (operator == '+') {
        result = addition(num1, num2);
    } else if (operator == '-') {
        result = subtraction(num1, num2);
    } else if (operator == '*') {
        result = multiplication(num1, num2);
    } else if (operator == '/') {
        result = division(num1, num2);
    } else {
        printf("Invalid operator!\n");
        return 1;
    }

    printf("Result: %d\n", result);

    return 0;
}

// Function to perform addition
int addition(int num1, int num2) {
    return num1 + num2;
}

// Function to perform subtraction
int subtraction(int num1, int num2) {
    return num1 - num2;
}

// Function to perform multiplication
int multiplication(int num1, int num2) {
    return num1 * num2;
}

// Function to perform division
int division(int num1, int num2) {
    if (num2 == 0) {
        printf("Division by zero is not allowed!\n");
        exit(1);
    }
    return num1 / num2;
}