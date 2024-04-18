#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int regNo;
    char firstName[50];
    char lastName[50];
    char courses[3][50];
};

int main() {
    struct Student students[2];

    for (int s = 0; s < 2; s++) {
        printf("Enter details for Student %d:\n", s + 1);
        printf("Enter Registration Number: ");
        scanf("%d", &students[s].regNo);

        printf("Enter First Name: ");
        scanf("%s", students[s].firstName);

        printf("Enter Last Name: ");
        scanf("%s", students[s].lastName);

        printf("Enter Three Courses: \n");
        for (int i = 0; i < 3; i++) {
            printf("Course %d: ", i + 1);
            scanf("%s", students[s].courses[i]);
        }
    }

    for (int s = 0; s < 2; s++) {
        printf("\nStudent %d Details:\n", s + 1);
        printf("Registration Number: %d\n", students[s].regNo);
        printf("Name: %s %s\n", students[s].firstName, students[s].lastName);
        printf("Courses:\n");
        for (int i = 0; i < 3; i++) {
            printf("- %s\n", students[s].courses[i]);
        }
    }

    // Open a file for writing
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write details for each student to the file
    for (int s = 0; s < 2; s++) {
        fprintf(file, "Student %d Details:\n", s + 1);
        fprintf(file, "Registration Number: %d\n", students[s].regNo);
        fprintf(file, "Name: %s %s\n", students[s].firstName, students[s].lastName);
        fprintf(file, "Courses:\n");
        for (int i = 0; i < 3; i++) {
            fprintf(file, "- %s\n", students[s].courses[i]);
        }
        fprintf(file, "\n");
    }

    // Close the file
    fclose(file);

    printf("Student details written to file successfully.\n");

    // Allow the user to edit student details from the file
    printf("\nEnter the registration number of the student you want to edit: ");
    int regNo;
    scanf("%d", &regNo);

    file = fopen("students.txt", "r+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Registration Number:")) {
            int fileRegNo;
            sscanf(line, "Registration Number: %d", &fileRegNo);
            if (fileRegNo == regNo) {
                found = 1;
                printf("Student found. Enter new details:\n");
                printf("Enter First Name: ");
                scanf("%s", students[0].firstName);
                printf("Enter Last Name: ");
                scanf("%s", students[0].lastName);
                printf("Enter Three Courses: \n");
                for (int i = 0; i < 3; i++) {
                    printf("Course %d: ", i + 1);
                    scanf("%s", students[0].courses[i]); 
                }
                fseek(file, -strlen(line), SEEK_CUR);
                fprintf(file, "Registration Number: %d\n", students[0].regNo);   
                fprintf(file, "Name: %s %s\n", students[0].firstName, students[0].lastName);   
                fprintf(file, "Courses:\n");
                for (int i = 0; i < 3; i++) {
                    fprintf(file, "- %s\n", students[0].courses[i]);
                }
                break;
            }
        }
    }

    if (!found) {
        printf("Student with registration number %d not found.\n", regNo);
    } else {
        printf("Student details updated successfully.\n");
    }

    // Close the file
    fclose(file);

    return 0;
}