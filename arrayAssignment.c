#include <stdio.h>

#define MAX_SIZE 100

void arrangeAscending(int arr[], int size);
void printArray(int arr[], int size);
void removeElement(int arr[], int *size);
void insertElement(int arr[], int *size, int element);

int main() {
    int arr[MAX_SIZE];
    int size;

    // Prompt user to insert array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Arrange and print array in ascending order
    arrangeAscending(arr, size);
    printf("Array in ascending order: ");
    printArray(arr, size);

    // Remove element
    removeElement(arr, &size);
    printf("Array after removing element: ");
    printArray(arr, size);

    // Insert element
    int element;
    printf("Enter the element to be added: ");
    scanf("%d", &element);
    insertElement(arr, &size, element);
    printf("Array after adding element: ");
    printArray(arr, size);

    return 0;
}

// Function to arrange array elements in ascending order
void arrangeAscending(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to remove an element from the array
void removeElement(int arr[], int *size) {
    int position;
    printf("Enter the position of the element to be removed (0-indexed): ");
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

// Function to insert an element into the array maintaining ascending order
void insertElement(int arr[], int *size, int element) {
    int i = *size - 1;
    while (i >= 0 && arr[i] > element) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
    (*size)++;
}