#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char buffer[100];

    // Append new data to input.txt
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);
    inputFile = fopen("C:\\Users\\kidsa\\Searches\\dsac\\ICS2371\\input.txt", "a"); // "a" mode for append
    if (inputFile == NULL) {
        printf("Error appending to input.txt\n");
        return 1;
    }
    fputs(buffer, inputFile);
    fclose(inputFile);

    
    inputFile = fopen("C:\\Users\\kidsa\\Searches\\dsac\\ICS2371\\input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    
    outputFile = fopen("C:\\Users\\kidsa\\Searches\\dsac\\ICS2371\\output.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating/output.txt\n");
        fclose(inputFile);
        return 1;
    }

    
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        fputs(buffer, outputFile);
    }

   
    fclose(inputFile);
    fclose(outputFile);

    printf("File copied successfully.\n");
    return 0;
}
