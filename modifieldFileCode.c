// I mantained the Adresses

#include <stdio.h>
int main() {
    FILE *inputFile, *outputFile;
    char buffer[100];

    // Append new data to input.txt
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);
    inputFile = fopen("C:\\Users\\sospe\\Documents\\ECE\\ECE3.2\\ICS2371 Structural Programming\\input.txt", "a"); // "a" mode for append
    if (inputFile == NULL) {
        printf("Error appending to input.txt\n");
        return 1;
    }
    fputs(buffer, inputFile);
    fclose(inputFile);

    
    inputFile = fopen("C:\\Users\\sospe\\Documents\\ECE\\ECE3.2\\ICS2371 Structural Programming\\input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    
    outputFile = fopen("C:\\Users\\sospe\\Documents\\ECE\\ECE3.2\\ICS2371 Structural Programming\\output.txt", "w");
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
