#include <stdio.h>
#include <stdlib.h> 

#define MAX_ROWS 10
#define MAX_COLS 10

int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
int rows1, cols1, rows2, cols2;


void inputMatrices();
void multiplyMatrices();
void displayResult();

int main() {
    inputMatrices();
    multiplyMatrices();
    displayResult();

    return 0;
}

void inputMatrices() {
    printf("Enter the number of rows and columns for the first matrix (format: rows columns): ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter elements of the first matrix row by row (format: row1elem1 row1elem2 ...):\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix (format: rows columns): ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter elements of the second matrix row by row (format: row1elem1 row1elem2 ...):\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    if (cols1 != rows2) {
        printf("Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        exit(1); 
    }
}

void multiplyMatrices() {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayResult() {
    printf("\nResultant Matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}