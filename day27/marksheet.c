#include <stdio.h>
#include <string.h>

#define NUM_SUBJECTS 5
#define MAX_NAME_LEN 50

// Structure to group student details together
struct Student {
    char name[MAX_NAME_LEN];
    int rollNumber;
    int marks[NUM_SUBJECTS];
    int totalMarks;
    float percentage;
    char grade;
    const char* status;
};

// Array of subject names for cleaner processing
const char* subjectNames[NUM_SUBJECTS] = {
    "Mathematics",
    "Physics",
    "Chemistry",
    "English",
    "Computer Science"
};

// Function prototypes
void calculateResults(struct Student *s);
char evaluateGrade(float percentage);
void printMarksheet(struct Student s);

int main() {
    struct Student student;
    int i;

    printf("==========================================\n");
    printf("     STUDENT MARKSHEET GENERATOR SYSTEM   \n");
    printf("==========================================\n\n");

    // Input Student Info
    printf("Enter Student Full Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    // Remove newline character caught by fgets
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &student.rollNumber);

    // Input & Validate Academic Marks
    printf("\nEnter marks obtained out of 100:\n");
    for (i = 0; i < NUM_SUBJECTS; i++) {
        while (1) {
            printf("  %s: ", subjectNames[i]);
            scanf("%d", &student.marks[i]);

            // Boundary validation check
            if (student.marks[i] >= 0 && student.marks[i] <= 100) {
                break; // Valid score, exit loop
            }
            printf("  [Error] Invalid input. Marks must range between 0 and 100.\n");
        }
    }

    // Process calculations
    calculateResults(&student);

    // Render formatted report card
    printMarksheet(student);

    return 0;
}

// Function to handle core data compilation
void calculateResults(struct Student *s) {
    s->totalMarks = 0;
    int failedANySubject = 0;

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        s->totalMarks += s->marks[i];
        if (s->marks[i] < 33) { // 33 is standard minimal pass mark
            failedANySubject = 1;
        }
    }

    s->percentage = (float)s->totalMarks / NUM_SUBJECTS;
    s->grade = evaluateGrade(s->percentage);
    
    // Status assignment logic
    if (failedANySubject) {
        s->status = "FAIL (Failed one or more subjects)";
    } else if (s->percentage >= 33.0) {
        s->status = "PASS";
    } else {
        s->status = "FAIL";
    }
}

// Helper function to return Grade tiers based on percentage boundaries
char evaluateGrade(float percentage) {
    if (percentage >= 85.0) return 'A';
    if (percentage >= 70.0) return 'B';
    if (percentage >= 55.0) return 'C';
    if (percentage >= 33.0) return 'D';
    return 'F';
}

// Function to generate the visually polished transcript
void printMarksheet(struct Student s) {
    printf("\n\n====================================================\n");
    printf("                 OFFICIAL REPORT CARD               \n");
    printf("====================================================\n");
    printf(" Student Name : %-30s\n", s.name);
    printf(" Roll Number  : %-30d\n", s.rollNumber);
    printf("----------------------------------------------------\n");
    printf(" %-25s | %-15s\n", "SUBJECT", "MARKS OBTAINED");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf(" %-25s | %-15d\n", subjectNames[i], s.marks[i]);
    }

    printf("----------------------------------------------------\n");
    printf(" Aggregate Total   : %d / %d\n", s.totalMarks, NUM_SUBJECTS * 100);
    printf(" Final Percentage  : %.2f%%\n", s.percentage);
    printf(" Letter Grade      : %c\n", s.grade);
    printf(" Academic Status   : %s\n", s.status);
    printf("====================================================\n");
}