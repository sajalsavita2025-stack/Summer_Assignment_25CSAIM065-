#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNo;
    char name[50];
    float gpa;
} Student;

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase full!\n");
        return;
    }
    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].rollNo);
    getchar(); // Clear newline buffer
    printf("Enter Name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0; // Remove trailing newline
    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);
    
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    printf("%-10s %-30s %-5s\n", "Roll No", "Name", "GPA");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-5.2f\n", students[i].rollNo, students[i].name, students[i].gpa);
    }
}

void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("\nNo records to search.\n");
        return;
    }
    int searchRoll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);
    
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == searchRoll) {
            printf("\nRecord Found:\n");
            printf("Roll No: %d\nName: %s\nGPA: %.2f\n", students[i].rollNo, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", searchRoll);
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=== Student Record Management System ===");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student by Roll No");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: displayStudents(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}